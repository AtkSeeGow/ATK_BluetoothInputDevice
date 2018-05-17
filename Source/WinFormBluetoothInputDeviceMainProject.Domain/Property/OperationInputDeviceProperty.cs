using System;
using System.Runtime.InteropServices;

namespace WinFormBluetoothInputDeviceMainProject.Domain
{
    /// <summary>
    /// 輸入設備實作
    /// </summary>
    public static partial class OperationInputDevice
    {
        [StructLayout(LayoutKind.Explicit, Pack = 1, Size = 28)]
        public struct Input
        {
            [FieldOffset(0)]
            public InputType dwType;
            [FieldOffset(4)]
            public MouseInput mi;
            [FieldOffset(4)]
            public KeyboardInput ki;
            [FieldOffset(4)]
            public HardwareInput hi;
        }

        /// <summary>
        /// 滑鼠
        /// </summary>
        [StructLayout(LayoutKind.Sequential, Pack = 1)]
        public struct MouseInput
        {
            public Int32 dx;
            public Int32 dy;
            public Int32 mouseData;
            public MouseFlag dwFlags;
            public Int32 time;
            public IntPtr dwExtraInfo;
        }

        /// <summary>
        /// 鍵盤
        /// </summary>
        [StructLayout(LayoutKind.Sequential, Pack = 1)]
        public struct KeyboardInput
        {
            public Int16 wVk;
            public Int16 wScan;
            public KeyboardFlag dwFlags;
            public Int32 time;
            public IntPtr dwExtraInfo;
        }

        /// <summary>
        /// 輸入設備模擬訊息
        /// </summary>
        [StructLayout(LayoutKind.Sequential, Pack = 1)]
        public struct HardwareInput
        {
            public Int32 uMsg;
            public Int16 wParamL;
            public Int16 wParamH;
        }
    }
}







