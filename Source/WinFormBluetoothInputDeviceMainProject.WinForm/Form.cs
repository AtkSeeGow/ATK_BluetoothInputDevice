using WinFormBluetoothInputDeviceMainProject.Domain;
using InTheHand.Net.Bluetooth;
using InTheHand.Net.Sockets;
using System;
using System.Collections.Generic;
using System.Threading;
using System.Windows.Forms;

namespace WinFormBluetoothInputDeviceMainProject.WinForm
{
    public partial class Form : System.Windows.Forms.Form
    {
        /// <summary>
        /// 初始化藍芽監聽器(硬體)
        /// </summary>
        private BluetoothListener bluetoothListener;

        /// <summary>
        /// 連線監聽處理執行緒
        /// </summary>
        private System.Threading.Thread operationConnectListenerThread;

        /// <summary>
        /// 在線監聽處理執行緒
        /// </summary>
        private System.Threading.Thread operationOnlineListenerThread;

        /// <summary>
        /// 解析實作集合
        /// </summary>
        private List<InstructionParsing> instructionParsingsForTarget = new List<InstructionParsing>();

        public Form()
        {
            InitializeComponent();
        }

        private void Form_Load(object sender, EventArgs e)
        {
            System.Windows.Forms.Form.CheckForIllegalCrossThreadCalls = false;

            BluetoothRadio bluetoothRadio = BluetoothRadio.PrimaryRadio;
            bluetoothRadio.Mode = RadioMode.Discoverable;

            bluetoothListener = new BluetoothListener(BluetoothService.SerialPort);
            
            operationOnlineListenerThread = new System.Threading.Thread(operationOnlineListener);
            operationOnlineListenerThread.IsBackground = true;
            operationOnlineListenerThread.Start();

            listenerStartAction();
        }

        private void ListenerStartButton_Click(object sender, EventArgs e)
        {
            listenerStartAction();
        }

        private void listenerStartAction()
        {
            bluetoothListener.Start();

            if (operationConnectListenerThread == null || operationConnectListenerThread.IsAlive)
            {
                operationConnectListenerThread = new System.Threading.Thread(operationConnectListener);
                operationConnectListenerThread.IsBackground = true;
                operationConnectListenerThread.Start();
            }

            ListenerStatusValueLabel.Text = "Listener Start!";
        }

        private void ListenerStopButton_Click(object sender, EventArgs e)
        {
            try
            {
                bluetoothListener.Stop();

                operationConnectListenerThread.Abort();

                ListenerStatusValueLabel.Text = "Listener Stop!";
            }
            catch (Exception exception)
            {
                MessageBox.Show(exception.Message, "ListenerStopButton_Click 出現錯誤..", MessageBoxButtons.OK, MessageBoxIcon.Question);
            }
        }
        
        /// <summary>
        /// 藍芽連線監聽處理 ( 獨立執行緒 )
        /// </summary>
        private void operationConnectListener()
        {
            while (true)
            {
                try
                {
                    BluetoothClient bluetoothClient = bluetoothListener.AcceptBluetoothClient();

                    var instructionParsing = new InstructionParsing(int.Parse(DelayTimeTextBox.Text), bluetoothClient);
                    instructionParsing.InstructionParsingThread.Start();
                    instructionParsingsForTarget.Add(instructionParsing);
                }
                catch (Exception exception)
                {
                    MessageBox.Show(exception.Message, "operationConnectListener 出現錯誤..", MessageBoxButtons.OK, MessageBoxIcon.Question);
                }
            }
        }

        private void operationOnlineListener()
        {
            var instructionParsingsForTemp = new List<InstructionParsing>();
            var heartBeat = new byte[] { ActionParsingCode.HeartBeat };

            while (true)
            {
                Thread.Sleep(1000);
                try
                {
                    instructionParsingsForTemp.Clear();
                    foreach (var instructionParsing in instructionParsingsForTarget)
                        instructionParsingsForTemp.Add(instructionParsing);
                    
                    foreach (var instructionParsing in instructionParsingsForTemp)
                    {
                        try
                        {
                            instructionParsing.BluetoothClient.GetStream().Write(heartBeat, 0, heartBeat.Length);
                        }
                        catch
                        {
                            instructionParsing.InterruptedConnection();
                            instructionParsingsForTarget.Remove(instructionParsing);
                        }
                    }

                    DataGridViewRowCollection dataGridViewRowCollection = OnlineBuletoothClientList.Rows;
                    if (instructionParsingsForTarget.Count + 1 != dataGridViewRowCollection.Count)
                    {
                        dataGridViewRowCollection.Clear();

                        foreach (var instructionParsing in instructionParsingsForTarget)
                            dataGridViewRowCollection.Add(new Object[] { instructionParsing.BluetoothClient.RemoteMachineName, instructionParsing.BluetoothClient.RemoteEndPoint.ToString(), DateTime.Now.ToString(), DelayTimeTextBox.Text });
                    }
                }
                catch (Exception exception)
                {
                    MessageBox.Show(exception.Message, "operationOnlineListener 出現錯誤..", MessageBoxButtons.OK, MessageBoxIcon.Question);
                }
            }
        }
    }
}