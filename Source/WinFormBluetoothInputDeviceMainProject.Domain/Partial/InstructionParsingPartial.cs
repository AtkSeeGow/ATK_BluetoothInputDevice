using InTheHand.Net.Sockets;
using System;
using System.Drawing;
using System.IO;
using System.Threading;
using System.Windows.Forms;

namespace WinFormBluetoothInputDeviceMainProject.Domain
{
    /// <summary>
    /// 手機端相對操作與解析實作
    /// </summary>
    public partial class InstructionParsing
    {
        public InstructionParsing(int dragDoubleClickDelayTime, BluetoothClient bluetoothClient)
        {
            this.BluetoothClient = bluetoothClient;
            this.DragDoubleClickDelayTime = dragDoubleClickDelayTime;
            this.InstructionParsingThread = new Thread(this.OperationInstructionParsing);
            this.InstructionParsingThread.SetApartmentState(ApartmentState.STA);
            this.InstructionParsingThread.IsBackground = true;
        }

        public void OperationInstructionParsing()
        {
            using (var stream = BluetoothClient.GetStream())
            {
                while (true)
                {
                    if (stream.CanRead)
                    {
                        try
                        {
                            stream.Read(streamBuffer, 0, 1);
                            byte value = streamBuffer[0];

                            // 傳輸資料開始
                            if (value == ActionParsingCode.SendInputStartKey)
                                this.isInputStatus = true;
                            // 傳輸資料結束
                            else if (value == ActionParsingCode.SendInputEndKey)
                                this.inputAction();
                            else if(isInputStatus)
                                this.inputByteList.Add(value);
                            else if (value == ActionParsingCode.RelativeCoordinates || value == ActionParsingCode.DragDoubleClick || value == ActionParsingCode.Wheel)
                                actionParsingCode = value;
                            else if (value == ActionParsingCode.CoordinateDataEnd)
                                coordinateDataEndAction();
                            // 滑鼠左鍵點擊
                            else if (value == ActionParsingCode.MouseLeftClick)
                                OperationInputDevice.MouseLeftClick();
                            // 滑鼠右鍵點擊
                            else if (value == ActionParsingCode.MouseRightClick)
                                OperationInputDevice.MouseRightClick();
                            // 方向鍵上點擊
                            else if (value == ActionParsingCode.ArrowUpKey)
                                OperationInputDevice.KeyboardKeyPress(0x26);
                            // 方向鍵下點擊
                            else if (value == ActionParsingCode.ArrowDownKey)
                                OperationInputDevice.KeyboardKeyPress(0x28);
                            // 方向鍵左點擊
                            else if (value == ActionParsingCode.ArrowLeftKey)
                                OperationInputDevice.KeyboardKeyPress(0x25);
                            // 方向鍵右點擊
                            else if (value == ActionParsingCode.ArrowRightKey)
                                OperationInputDevice.KeyboardKeyPress(0x27);
                            // Backspace點擊
                            else if (value == ActionParsingCode.BackspaceKey)
                                OperationInputDevice.KeyboardKeyPress(0x8);
                            else if (value == ActionParsingCode.TouchScreen)
                                touchScreenAction();
                            else if (value == ActionParsingCode.LeaveScreen)
                                leaveScreenAction();
                            else if (value == ActionParsingCode.CoordinateX || value == ActionParsingCode.CoordinateY)
                                coordinateType = value;
                            else
                                coordinateDataSettingAction(System.Text.UTF8Encoding.UTF8.GetString(streamBuffer, 0, 1));
                        }
                        catch
                        {
                            this.InterruptedConnection();
                        }
                    }
                }
            }
        }

        public void InterruptedConnection()
        {
            this.InstructionParsingThread.Abort();
            this.BluetoothClient.Close();
        }

        /// <summary>
        /// 座標資料結束事件
        /// </summary>
        private void coordinateDataEndAction()
        {
            var coordinateValueX = int.Parse(coordinateX.ToString());
            var coordinateValueY = int.Parse(coordinateY.ToString());
            
            if(previousCoordinateX != 0 && previousCoordinateY != 0)
            {
                if (actionParsingCode == ActionParsingCode.Wheel)
                {
                    var distance = coordinateValueY - previousCoordinateY;
                    OperationInputDevice.MouseScrollWheel(distance);
                }
                else
                {
                    var movePointX = coordinateValueX - previousCoordinateX;
                    var movePoistY = coordinateValueY - previousCoordinateY;
                    OperationInputDevice.MouseMove(movePointX, movePoistY);
                }
            }
            
            previousCoordinateX = coordinateValueX;
            previousCoordinateY = coordinateValueY;

            coordinateX.Clear();
            coordinateY.Clear();
        }

        /// <summary>
        /// 座標資料設定事件
        /// </summary>
        /// <param name="value"></param>
        private void coordinateDataSettingAction(string value)
        {
            if (coordinateType == ActionParsingCode.CoordinateX)
                coordinateX.Append(value);
            else
                coordinateY.Append(value);
        }

        /// <summary>
        /// 離開螢幕事件
        /// </summary>
        private void leaveScreenAction()
        {
            previousCoordinateX = 0;
            previousCoordinateY = 0;
            previousleaveScreenTime = DateTime.Now;

            if (isMouseLeftDownStatus)
            {
                isMouseLeftDownStatus = false;
                OperationInputDevice.MouseLeftUp();
            }
        }

        /// <summary>
        /// 觸控螢幕事件
        /// </summary>
        private void touchScreenAction()
        {
            if (previousleaveScreenTime.AddMilliseconds(DragDoubleClickDelayTime) > DateTime.Now)
            {
                isMouseLeftDownStatus = true;
                OperationInputDevice.MouseLeftDown();
            }
        }

        /// <summary>
        /// 輸入事件
        /// </summary>
        private void inputAction()
        {
            this.isInputStatus = false;

            var inputBuffer = new byte[this.inputByteList.Count];
            for (int i = 0; i < this.inputByteList.Count; i++)
                inputBuffer[i] = this.inputByteList[i];

            string target = System.Text.UTF8Encoding.UTF8.GetString(inputBuffer, 0, this.inputByteList.Count);

            Clipboard.SetText(target);
            SendKeys.SendWait("^{v}");

            this.inputByteList.Clear();
        }
    }
}
