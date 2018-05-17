using System;

namespace WinFormBluetoothInputDeviceMainProject.Domain
{
    /// <summary>
    /// 滑鼠動作標籤
    /// </summary>
    [Flags()]
    public enum MouseFlag : int
    {
        Move = 0x1,
        LeftDown = 0x2,
        LeftUp = 0x4,
        RightDown = 0x8,
        RightUp = 0x10,
        MiddleDown = 0x20,
        MiddleUp = 0x40,
        XDown = 0x80,
        XUp = 0x100,
        VirtualDesk = 0x400,
        Wheel = 0x800,
        Absolute = 0x8000
    }
}