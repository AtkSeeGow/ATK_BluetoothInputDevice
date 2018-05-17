using System;
using System.Runtime.InteropServices;
using System.Threading;

namespace WinFormBluetoothInputDeviceMainProject.Domain
{
    /// <summary>
    /// 輸入設備實作
    /// </summary>
    public static partial class OperationInputDevice
    {
        [DllImport("user32.dll", SetLastError = true)]
        public static extern Int32 SendInput(Int32 cInputs, ref Input pInputs, Int32 cbSize);

        [DllImport("user32.dll", EntryPoint = "mouse_event")]
        public static extern void mouse_event(int dwFlags, int dx, int dy, int dwData, int dwExtraInfo);

        [DllImport("user32.dll")]
        public static extern void keybd_event(byte bVk, byte bScan, uint dwFlags, UIntPtr dwExtraInfo);

        private static Input getInput()
        {
            Input result = new Input();
            result.dwType = 0;
            return result;
        }

        private static MouseInput getMouseInput(MouseFlag mouseFlag)
        {
            var result = new MouseInput();
            result.dwExtraInfo = IntPtr.Zero;
            result.dx = 0;
            result.dy = 0;
            result.time = 0;
            result.mouseData = 0;
            result.dwFlags = mouseFlag;
            return result;
        }

        /// <summary>
        /// 滑鼠移動
        /// </summary>
        public static void MouseMove(int dx, int dy)
        {
            mouse_event((int)MouseFlag.Move, dx, dy, 0, 0);
        }

        /// <summary>
        /// 滑鼠左鍵按下
        /// </summary>
        public static void MouseLeftDown()
        {
            Input result = getInput();
            result.mi = getMouseInput(MouseFlag.LeftDown);
            SendInput(1, ref result, Marshal.SizeOf(typeof(Input)));
        }

        /// <summary>
        /// 滑鼠左鍵放開
        /// </summary>
        public static void MouseLeftUp()
        {
            Input result = getInput();
            result.mi = getMouseInput(MouseFlag.LeftUp);
            SendInput(1, ref result, Marshal.SizeOf(typeof(Input)));
        }

        /// <summary>
        /// 滑鼠右鍵按下
        /// </summary>
        public static void MouseRightDown()
        {
            Input result = getInput();
            result.mi = getMouseInput(MouseFlag.RightDown);
            SendInput(1, ref result, Marshal.SizeOf(typeof(Input)));
        }

        /// <summary>
        /// 滑鼠右鍵放開
        /// </summary>
        public static void MouseRightUp()
        {
            Input result = getInput();
            result.mi = getMouseInput(MouseFlag.RightUp);
            SendInput(1, ref result, Marshal.SizeOf(typeof(Input)));
        }

        /// <summary>
        /// 滑鼠左鍵點一下
        /// </summary>
        public static void MouseLeftClick()
        {
            MouseLeftDown();
            Thread.Sleep(20);
            MouseLeftUp();
        }

        /// <summary>
        /// 滑鼠右鍵點一下
        /// </summary>
        public static void MouseRightClick()
        {
            MouseRightDown();
            Thread.Sleep(20);
            MouseRightUp();
        }

        /// <summary>
        /// 滑鼠中鍵滾動
        /// </summary>
        /// <param name="distance">滾動幅度</param>
        public static void MouseScrollWheel(int distance)
        {
            mouse_event((int)MouseFlag.Wheel, 0, 0, distance, 0);
        }

        /// <summary>
        /// 模擬按下指定的按鍵。
        /// </summary>
        public static void KeyboardKeyDown(Byte keyCode)
        {
            keybd_event(keyCode, 0x45, (int)KeyboardFlag.ExtendedKey, (UIntPtr)0);
        }

        /// <summary>
        /// 模擬釋放指定的按鍵。
        /// </summary>
        public static void KeyboardKeyUp(Byte keyCode)
        {
            keybd_event((Byte)keyCode, 0x45, (int)KeyboardFlag.ExtendedKey | (int)KeyboardFlag.KeyUp, (UIntPtr)0);
        }

        /// <summary>
        /// 模擬按下並釋放指定的按鍵。
        /// </summary>
        public static void KeyboardKeyPress(Byte keyCode)
        {
            KeyboardKeyDown(keyCode);
            KeyboardKeyUp(keyCode);
        }
    }
}







