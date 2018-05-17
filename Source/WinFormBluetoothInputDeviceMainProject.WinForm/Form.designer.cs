namespace WinFormBluetoothInputDeviceMainProject.WinForm
{
    partial class Form
    {
        /// <summary>
        /// 設計工具所需的變數。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清除任何使用中的資源。
        /// </summary>
        /// <param name="disposing">如果應該處置 Managed 資源則為 true，否則為 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 設計工具產生的程式碼

        /// <summary>
        /// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
        /// 修改這個方法的內容。
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form));
            this.ListenerStatusLable = new System.Windows.Forms.Label();
            this.SystemStatusValueLabel = new System.Windows.Forms.Label();
            this.ListenerStopButton = new System.Windows.Forms.Button();
            this.OnlineBuletoothClientList = new System.Windows.Forms.DataGridView();
            this.Name = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.MAC = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.ConnectDate = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.DelayTime = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.SystemStatusLable = new System.Windows.Forms.Label();
            this.ListenerStatusValueLabel = new System.Windows.Forms.Label();
            this.DelayTimeTextBox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.ListenerStartButton = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.OnlineBuletoothClientList)).BeginInit();
            this.SuspendLayout();
            // 
            // ListenerStatusLable
            // 
            this.ListenerStatusLable.AutoSize = true;
            this.ListenerStatusLable.Location = new System.Drawing.Point(12, 9);
            this.ListenerStatusLable.Name = "ListenerStatusLable";
            this.ListenerStatusLable.Size = new System.Drawing.Size(94, 16);
            this.ListenerStatusLable.TabIndex = 1;
            this.ListenerStatusLable.Text = "Listener Status :";
            // 
            // SystemStatusValueLabel
            // 
            this.SystemStatusValueLabel.AutoSize = true;
            this.SystemStatusValueLabel.Location = new System.Drawing.Point(112, 31);
            this.SystemStatusValueLabel.Name = "SystemStatusValueLabel";
            this.SystemStatusValueLabel.Size = new System.Drawing.Size(139, 16);
            this.SystemStatusValueLabel.TabIndex = 2;
            this.SystemStatusValueLabel.Text = "Initialization Complete!";
            // 
            // ListenerStopButton
            // 
            this.ListenerStopButton.Location = new System.Drawing.Point(382, 9);
            this.ListenerStopButton.Margin = new System.Windows.Forms.Padding(2, 3, 2, 3);
            this.ListenerStopButton.Name = "ListenerStopButton";
            this.ListenerStopButton.Size = new System.Drawing.Size(99, 67);
            this.ListenerStopButton.TabIndex = 3;
            this.ListenerStopButton.Text = "Listener Stop";
            this.ListenerStopButton.UseVisualStyleBackColor = true;
            this.ListenerStopButton.Click += new System.EventHandler(this.ListenerStopButton_Click);
            // 
            // OnlineBuletoothClientList
            // 
            this.OnlineBuletoothClientList.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.OnlineBuletoothClientList.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Name,
            this.MAC,
            this.ConnectDate,
            this.DelayTime});
            this.OnlineBuletoothClientList.Location = new System.Drawing.Point(15, 81);
            this.OnlineBuletoothClientList.Name = "OnlineBuletoothClientList";
            this.OnlineBuletoothClientList.RowTemplate.Height = 24;
            this.OnlineBuletoothClientList.Size = new System.Drawing.Size(466, 206);
            this.OnlineBuletoothClientList.TabIndex = 4;
            // 
            // Name
            // 
            this.Name.HeaderText = "Name";
            this.Name.Name = "Name";
            this.Name.ReadOnly = true;
            // 
            // MAC
            // 
            this.MAC.HeaderText = "MAC";
            this.MAC.Name = "MAC";
            this.MAC.ReadOnly = true;
            // 
            // ConnectDate
            // 
            this.ConnectDate.HeaderText = "ConnectDate";
            this.ConnectDate.Name = "ConnectDate";
            this.ConnectDate.ReadOnly = true;
            // 
            // DelayTime
            // 
            this.DelayTime.HeaderText = "DelayTime";
            this.DelayTime.Name = "DelayTime";
            this.DelayTime.ReadOnly = true;
            // 
            // SystemStatusLable
            // 
            this.SystemStatusLable.AutoSize = true;
            this.SystemStatusLable.Location = new System.Drawing.Point(12, 31);
            this.SystemStatusLable.Name = "SystemStatusLable";
            this.SystemStatusLable.Size = new System.Drawing.Size(91, 16);
            this.SystemStatusLable.TabIndex = 5;
            this.SystemStatusLable.Text = "System Status :";
            // 
            // ListenerStatusValueLabel
            // 
            this.ListenerStatusValueLabel.AutoSize = true;
            this.ListenerStatusValueLabel.Location = new System.Drawing.Point(112, 9);
            this.ListenerStatusValueLabel.Name = "ListenerStatusValueLabel";
            this.ListenerStatusValueLabel.Size = new System.Drawing.Size(139, 16);
            this.ListenerStatusValueLabel.TabIndex = 6;
            this.ListenerStatusValueLabel.Text = "Initialization Complete!";
            // 
            // DelayTimeTextBox
            // 
            this.DelayTimeTextBox.Location = new System.Drawing.Point(115, 53);
            this.DelayTimeTextBox.Name = "DelayTimeTextBox";
            this.DelayTimeTextBox.Size = new System.Drawing.Size(100, 23);
            this.DelayTimeTextBox.TabIndex = 7;
            this.DelayTimeTextBox.Text = "125";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 56);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(77, 16);
            this.label1.TabIndex = 8;
            this.label1.Text = "Delay Time :";
            // 
            // ListenerStartButton
            // 
            this.ListenerStartButton.Location = new System.Drawing.Point(279, 9);
            this.ListenerStartButton.Margin = new System.Windows.Forms.Padding(2, 3, 2, 3);
            this.ListenerStartButton.Name = "ListenerStartButton";
            this.ListenerStartButton.Size = new System.Drawing.Size(99, 67);
            this.ListenerStartButton.TabIndex = 9;
            this.ListenerStartButton.Text = "Listener Start";
            this.ListenerStartButton.UseVisualStyleBackColor = true;
            this.ListenerStartButton.Click += new System.EventHandler(this.ListenerStartButton_Click);
            // 
            // Form
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.ClientSize = new System.Drawing.Size(496, 298);
            this.Controls.Add(this.ListenerStartButton);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.DelayTimeTextBox);
            this.Controls.Add(this.ListenerStatusValueLabel);
            this.Controls.Add(this.SystemStatusLable);
            this.Controls.Add(this.OnlineBuletoothClientList);
            this.Controls.Add(this.ListenerStopButton);
            this.Controls.Add(this.SystemStatusValueLabel);
            this.Controls.Add(this.ListenerStatusLable);
            this.Font = new System.Drawing.Font("微軟正黑體", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(2, 3, 2, 3);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Load += new System.EventHandler(this.Form_Load);
            ((System.ComponentModel.ISupportInitialize)(this.OnlineBuletoothClientList)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label ListenerStatusLable;
        private System.Windows.Forms.Label SystemStatusValueLabel;
        private System.Windows.Forms.Button ListenerStopButton;
        private System.Windows.Forms.DataGridView OnlineBuletoothClientList;
        private System.Windows.Forms.Label SystemStatusLable;
        private System.Windows.Forms.Label ListenerStatusValueLabel;
        private System.Windows.Forms.TextBox DelayTimeTextBox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.DataGridViewTextBoxColumn Name;
        private System.Windows.Forms.DataGridViewTextBoxColumn MAC;
        private System.Windows.Forms.DataGridViewTextBoxColumn ConnectDate;
        private System.Windows.Forms.DataGridViewTextBoxColumn DelayTime;
        private System.Windows.Forms.Button ListenerStartButton;
    }
}

