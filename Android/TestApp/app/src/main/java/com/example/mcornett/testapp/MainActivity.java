package com.example.mcornett.testapp;


        import java.io.IOException;
        import java.io.InputStream;
        import java.io.OutputStream;
        import java.lang.reflect.Method;
        import java.util.UUID;

        import android.app.Activity;
        import android.bluetooth.BluetoothAdapter;
        import android.bluetooth.BluetoothDevice;
        import android.bluetooth.BluetoothSocket;
        import android.content.Intent;
        import android.media.MediaPlayer;
        import android.os.Build;
        import android.os.Bundle;
        import android.os.Handler;
        import android.util.Log;
        import android.view.View;
        import android.view.View.OnClickListener;
        import android.widget.ImageButton;
        import android.content.Context;

        import android.widget.Toast;
        import android.content.IntentFilter;

public class MainActivity extends Activity {
    private static final String TAG = "bluetooth1";

    ImageButton btnOn, btnOff, restart, reset, endGame;
    Handler handler;
    final int RECIEVE_MESSAGE = 1;
    private BluetoothAdapter btAdapter = null;
    private BluetoothSocket btSocket = null;
    private String deviceName = null;
    private OutputStream outStream = null;
    private InputStream inStream = null;
    private StringBuilder sb = new StringBuilder();
    private ConnectedThread mConnectedThread;
    private  MediaPlayer m1;
    private  MediaPlayer m2;
    private  MediaPlayer m3;
    private  MediaPlayer boing;
    private  MediaPlayer giggle;
    private boolean mute = false;
    private boolean isOff = false;
    IntentFilter filter1 = new IntentFilter(BluetoothDevice.ACTION_ACL_CONNECTED);
    IntentFilter filter2 = new IntentFilter(BluetoothDevice.ACTION_ACL_DISCONNECT_REQUESTED);
    IntentFilter filter3 = new IntentFilter(BluetoothDevice.ACTION_ACL_DISCONNECTED);
//    this.registerReceiver(mReceiver, filter1);
//    this.registerReceiver(mReceiver, filter2);
//    this.registerReceiver(mReceiver, filter3);


    // SPP UUID service
    private static final UUID MY_UUID = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");

    // MAC-address of Bluetooth module (you must edit this line)
    private static String address = "98:D3:31:30:0C:5C";

    /** Called when the activity is first created. */

    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_main);
        m1 = MediaPlayer.create(getBaseContext(), R.raw.douglass);
        m2 = MediaPlayer.create(getBaseContext(), R.raw.ears);
        m3 = MediaPlayer.create(getBaseContext(), R.raw.wheels);
        giggle = MediaPlayer.create(getBaseContext(), R.raw.giggles);
        boing = MediaPlayer.create(getBaseContext(), R.raw.boing);
        btnOn = (ImageButton) findViewById(R.id.btnOn);
        btnOff = (ImageButton) findViewById(R.id.btnOff);
        restart = (ImageButton) findViewById(R.id.restart);
        reset = (ImageButton) findViewById(R.id.reset);
        endGame = (ImageButton) findViewById(R.id.endGame);

        handler = new Handler() {

            public void handleMessage(android.os.Message msg) {
                switch (msg.what) {
                    case RECIEVE_MESSAGE:                                                   // if receive massage

                        byte[] readBuf = (byte[]) msg.obj;
                        String strIncom = new String(readBuf, 0, msg.arg1);                 // create string from bytes array
                        sb.append(strIncom);                                                // append string
                        Log.d(TAG, sb.toString());


                        int endOfLineIndex = sb.indexOf("\r\n");                            // determine the end-of-line
                        if (endOfLineIndex > 0) {                                            // if end-of-line,

                            if (sb.charAt(0) == 'a') {
                                if (!m1.isPlaying() && !m2.isPlaying() && !m3.isPlaying()) {
                                    m1.start();
                                    //mConnectedThread.write("zzz");
                                } else if (!giggle.isPlaying()){
                                    giggle.start();
                                }
                            }
                            else if (sb.charAt(0) == 'b') {
                                if (!m1.isPlaying() && !m2.isPlaying() && !m3.isPlaying()) {
                                    m2.start();
                                    //mConnectedThread.write("zzz");
                                }else if (!giggle.isPlaying()){
                                    giggle.start();
                                }
                            }
                            else if (sb.charAt(0) == 'c') {
                                if (!m1.isPlaying() && !m2.isPlaying() && !m3.isPlaying()) {
                                    m3.start();
                                    //mConnectedThread.write("zzz");
                                }else if (!giggle.isPlaying()){
                                    giggle.start();
                                }
                            }
//                            else if (sb.charAt(0) == 'g') {
//                                if (!giggle.isPlaying()) {
//                                    giggle.start();
//                                    m1.start();
//                                    //mConnectedThread.write("iii");
//                                }
//                            }
//                            else if (sb.charAt(0) == 'h') {
//                                if (!boing.isPlaying()) {
//                                    boing.start();
//                                    //mConnectedThread.write("jjj");
//                                }
//                            }
                            sb.delete(0, sb.length());                                      // and clear
                            btnOff.setEnabled(true);
                            btnOn.setEnabled(true);
                        }
                        break;
                }
            };
        };
        btAdapter = BluetoothAdapter.getDefaultAdapter();
        checkBTState();


        endGame.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {

                if (!isOff) {
                    m1.setVolume(0, 0);
                    m2.setVolume(0, 0);
                    m3.setVolume(0, 0);
                    boing.setVolume(0,0);
                    giggle.setVolume(0,0);
                    isOff = true;
                    mConnectedThread.write("ooo");
                }
            }
        });

        btnOn.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                Log.d(TAG, "lights on off");
                if (!isOff) {
                    mConnectedThread.write("000");
                }
            }
        });

        reset.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                mConnectedThread.write("qqq");
                isOff = false;
            }
        });

        btnOff.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                if (!isOff) {
                    mute = !mute;

                    if (mute) {
                        m1.setVolume(0, 0);
                        m2.setVolume(0, 0);
                        m3.setVolume(0, 0);
                        boing.setVolume(0,0);
                        giggle.setVolume(0,0);
                    } else {
                        m1.setVolume(1, 1);
                        m2.setVolume(1, 1);
                        m3.setVolume(1, 1);
                        boing.setVolume(1,1);
                        giggle.setVolume(1,1);
                    }

                    mConnectedThread.write("111");
                }

            }
        });

        m1.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
            public void onCompletion(MediaPlayer mp) {
                mConnectedThread.write("zzz");
            }
        });
        m2.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
            public void onCompletion(MediaPlayer mp) {
                mConnectedThread.write("zzz");
            }
        });
        m3.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
            public void onCompletion(MediaPlayer mp) {
                mConnectedThread.write("zzz");
            }
        });
        giggle.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
            public void onCompletion(MediaPlayer mp) {
                mConnectedThread.write("GGG");
            }
        });
        boing.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
            public void onCompletion(MediaPlayer mp) {
                mConnectedThread.write("HHH");
            }
        });
        restart.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {

                BluetoothDevice device = btAdapter.getRemoteDevice(address);
                try {
                    Thread.sleep(500);
                } catch (Exception f){}
                try {

                    outStream.write("".getBytes());
                } catch (IOException e1) {
                    try {
                        btSocket.close();
                    } catch (Exception e){}
                        onResume();
                }
                try {
                    btSocket.connect();
                } catch (Exception e2) {
                    return;
                }
                onResume();
            }

        });



    }

    private BluetoothSocket createBluetoothSocket(BluetoothDevice device) throws IOException {
        if(Build.VERSION.SDK_INT >= 10){
            try {
                final Method  m = device.getClass().getMethod("createInsecureRfcommSocketToServiceRecord", new Class[] { UUID.class });
                return (BluetoothSocket) m.invoke(device, MY_UUID);
            } catch (Exception e) {
                Log.e(TAG, "Could not create Insecure RFComm Connection",e);
            }
        }
        return  device.createRfcommSocketToServiceRecord(MY_UUID);
    }

    @Override
    public void onResume() {
        super.onResume();

        Log.d(TAG, "...onResume - try connect...");

        // Set up a pointer to the remote node using it's address.
        BluetoothDevice device = btAdapter.getRemoteDevice(address);

        // Two things are needed to make a connection:
        //   A MAC address, which we got above.
        //   A Service ID or UUID.  In this case we are using the
        //     UUID for SPP.

        try {
            btSocket = createBluetoothSocket(device);
        } catch (IOException e1) {
            errorExit("Fatal Error", "In onResume() and socket create failed: " + e1.getMessage() + ".");
        }

        // Discovery is resource intensive.  Make sure it isn't going on
        // when you attempt to connect and pass your message.
        btAdapter.cancelDiscovery();

        // Establish the connection.  This will block until it connects.
        Log.d(TAG, "...Connecting...");
        try {
            btSocket.connect();
            Log.d(TAG, "...Connection ok...");
        } catch (IOException e) {
            try {
                btSocket.close();
            } catch (IOException e2) {
                errorExit("Fatal Error", "In onResume() and unable to close socket during connection failure" + e2.getMessage() + ".");
            }
        }

        // Create a data stream so we can talk to server.
        Log.d(TAG, "...Create Socket...");

        mConnectedThread = new ConnectedThread(btSocket);
        mConnectedThread.start();
        deviceName = device.getName();
    }

    @Override
    public void onPause() {
        super.onPause();

        Log.d(TAG, "...In onPause()...");

        if (outStream != null) {
            try {
                outStream.flush();
            } catch (IOException e) {
                errorExit("Fatal Error", "In onPause() and failed to flush output stream: " + e.getMessage() + ".");
            }
        }

        try     {
            btSocket.close();
        } catch (IOException e2) {
            errorExit("Fatal Error", "In onPause() and failed to close socket." + e2.getMessage() + ".");
        }
    }
//    @Override
//    public void onReceive(Context context, Intent intent) {
//        String action = intent.getAction();
//        BluetoothDevice device = intent.getParcelableExtra(BluetoothDevice.EXTRA_DEVICE);
//
//        if (BluetoothDevice.ACTION_FOUND.equals(action)) {
//            //Device found
//        }
//        else if (BluetoothDevice.ACTION_ACL_CONNECTED.equals(action)) {
//            //Device is now connected
//        }
//        else if (BluetoothAdapter.ACTION_DISCOVERY_FINISHED.equals(action)) {
//            //Done searching
//        }
//        else if (BluetoothDevice.ACTION_ACL_DISCONNECT_REQUESTED.equals(action)) {
//            //Device is about to disconnect
//        }
//        else if (BluetoothDevice.ACTION_ACL_DISCONNECTED.equals(action)) {
//            //Device has disconnected
//        }
//    }
    private void checkBTState() {
        // Check for Bluetooth support and then check to make sure it is turned on
        // Emulator doesn't support Bluetooth and will return null
        if(btAdapter==null) {
            errorExit("Fatal Error", "Bluetooth not support");
        } else {
            if (btAdapter.isEnabled()) {
                Log.d(TAG, "...Bluetooth ON...");
            } else {
                //Prompt user to turn on Bluetooth
                Intent enableBtIntent = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
                startActivityForResult(enableBtIntent, 1);
            }
        }
    }

    private void errorExit(String title, String message){
        Toast.makeText(getBaseContext(), title + " - " + message, Toast.LENGTH_LONG).show();
        finish();
    }

    private class ConnectedThread extends Thread {


        public ConnectedThread(BluetoothSocket socket) {
            InputStream tmpIn = null;
            OutputStream tmpOut = null;

            // Get the input and output streams, using temp objects because
            // member streams are final
            try {
                tmpIn = socket.getInputStream();
                tmpOut = socket.getOutputStream();
            } catch (IOException e) { }

            inStream = tmpIn;
            outStream = tmpOut;
        }

        public void run() {
            byte[] buffer = new byte[3];  // buffer store for the stream
            int bytes; // bytes returned from read()

            // Keep listening to the InputStream until an exception occurs
            while (true) {
                try {
                    // Read from the InputStream
                    bytes = inStream.read(buffer);        // Get number of bytes and message in "buffer"
                    handler.obtainMessage(RECIEVE_MESSAGE, bytes, -1, buffer).sendToTarget();     // Send to message queue Handler
                } catch (IOException e) {
                    break;
                }
            }
        }

        /* Call this from the main activity to send data to the remote device */
        public void write(String message) {
            Log.d(TAG, "...Data to send: " + message + "...");
            byte[] msgBuffer = message.getBytes();
            try {
               outStream.write(msgBuffer);
            } catch (IOException e) {
                Log.d(TAG, "...Error data send: " + e.getMessage() + "...");
            }
        }
    }
}

