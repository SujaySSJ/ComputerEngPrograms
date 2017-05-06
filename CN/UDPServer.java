import java.io.*;
import java.net.*;

class UDPServer{
   public static void main(String[] args) throws Exception {
      DatagramSocket serverSocket = new DatagramSocket(9999);
      byte receiveData[] =new byte[1024];
      byte sendData[]=new byte[1024];
      DatagramPacket receivePacket = new DatagramPacket(receiveData,receiveData.length);
      serverSocket.receive(receivePacket);
      String message=new String(receivePacket.getData());
      System.out.println("Received message: "+message);
      serverSocket.send(new DatagramPacket((message.toUpperCase()).getBytes(),sendData.length,receivePacket.getAddress(),receivePacket.getPort()));
   }
}