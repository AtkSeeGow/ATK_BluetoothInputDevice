
using System.Text;

namespace WinFormBluetoothInputDeviceMainProject.Domain
{
    /// <summary>
    /// 手機端動作解析代碼
    /// </summary>
    public static class ActionParsingCode
    {
        /// <summary>
        /// 相對座標
        /// </summary>
        public readonly static byte RelativeCoordinates = Encoding.UTF8.GetBytes("A")[0];
        /// <summary>
        /// X座標
        /// </summary>
        public readonly static byte CoordinateX = Encoding.UTF8.GetBytes("X")[0];
        /// <summary>
        /// Y座標
        /// </summary>
        public readonly static byte CoordinateY = Encoding.UTF8.GetBytes("Y")[0];
        /// <summary>
        /// 離開螢幕
        /// </summary>
        public readonly static byte LeaveScreen = Encoding.UTF8.GetBytes("U")[0];
        /// <summary>
        /// 座標資料結束
        /// </summary>
        public readonly static byte CoordinateDataEnd = Encoding.UTF8.GetBytes("C")[0];
        /// <summary>
        /// 左鍵點擊
        /// </summary>
        public readonly static byte MouseLeftClick = Encoding.UTF8.GetBytes("E")[0];
        /// <summary>
        /// 右鍵點擊
        /// </summary>
        public readonly static byte MouseRightClick = Encoding.UTF8.GetBytes("F")[0];
        /// <summary>
        /// 觸碰螢幕
        /// </summary>
        public readonly static byte TouchScreen = Encoding.UTF8.GetBytes("D")[0];
        /// <summary>
        /// 點擊後拖曳
        /// </summary>
        public readonly static byte DragDoubleClick = Encoding.UTF8.GetBytes("M")[0];
        /// <summary>
        /// 滾輪
        /// </summary>
        public readonly static byte Wheel = Encoding.UTF8.GetBytes("W")[0];
        /// <summary>
        /// 方向鍵上
        /// </summary>
        public readonly static byte ArrowUpKey = Encoding.UTF8.GetBytes("T")[0];
        /// <summary>
        /// 方向鍵右
        /// </summary>
        public readonly static byte ArrowRightKey = Encoding.UTF8.GetBytes("R")[0];
        /// <summary>
        /// 方向鍵左
        /// </summary>
        public readonly static byte ArrowLeftKey = Encoding.UTF8.GetBytes("L")[0];
        /// <summary>
        /// 方向鍵下
        /// </summary>
        public readonly static byte ArrowDownKey = Encoding.UTF8.GetBytes("B")[0];
        /// <summary>
        /// 心跳包
        /// </summary>
        public readonly static byte HeartBeat = Encoding.UTF8.GetBytes("H")[0];
        /// <summary>
        /// 傳入資料開始
        /// </summary>
        public readonly static byte SendInputStartKey = Encoding.UTF8.GetBytes("<")[0];
        /// <summary>
        /// 傳入資料開結束
        /// </summary>
        public readonly static byte SendInputEndKey = Encoding.UTF8.GetBytes(">")[0];
        /// <summary>
        /// Backspace
        /// </summary>
        public readonly static byte BackspaceKey = Encoding.UTF8.GetBytes("I")[0];
    }
}
