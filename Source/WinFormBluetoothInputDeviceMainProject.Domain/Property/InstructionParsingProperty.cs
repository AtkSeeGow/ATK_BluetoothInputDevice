using InTheHand.Net.Sockets;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Text;
using System.Threading;

namespace WinFormBluetoothInputDeviceMainProject.Domain
{
    /// <summary>
    /// 手機端相對操作與解析實作
    /// </summary>
    public partial class InstructionParsing
    {
        /// <summary>
        /// 用戶端連線資訊
        /// </summary>
        public BluetoothClient BluetoothClient;

        /// <summary>
        /// 指令解析執行緒
        /// </summary>
        public Thread InstructionParsingThread;

        /// <summary>
        /// 拖曳雙擊延遲時間
        /// </summary>
        public int DragDoubleClickDelayTime;

        /// <summary>
        /// 緩衝區
        /// </summary>
        byte[] streamBuffer = new byte[1000];

        /// <summary>
        /// 座標類型
        /// </summary>
        byte coordinateType = 0;

        /// <summary>
        /// 座標值(X)
        /// </summary>
        StringBuilder coordinateX = new StringBuilder();

        /// <summary>
        /// 座標值(Y)
        /// </summary>
        StringBuilder coordinateY = new StringBuilder();

        /// <summary>
        /// 前一座標值(X)
        /// </summary>
        int previousCoordinateX = 0;

        /// <summary>
        /// 座標值(Y)
        /// </summary>
        int previousCoordinateY = 0;

        /// <summary>
        /// 動作代號
        /// </summary>
        byte actionParsingCode = 0;

        /// <summary>
        /// 是否滑鼠右鍵點擊中
        /// </summary>
        bool isMouseLeftDownStatus = false;

        /// <summary>
        /// 上次離開螢幕時間
        /// </summary>
        DateTime previousleaveScreenTime = DateTime.Now;

        /// <summary>
        /// 是否為輸入狀態
        /// </summary>
        bool isInputStatus = false;

        /// <summary>
        /// 輸入緩衝區
        /// </summary>
        IList<byte> inputByteList = new List<byte>();
    }
}
