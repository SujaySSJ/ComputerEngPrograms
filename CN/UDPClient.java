import java.io.*;
import java.net.*;
import java.util.*;
class UDPClient{
   public static void main(String[] args) throws Exception {
      Scanner scr = new Scanner(System.in);
      DatagramSocket clientSocket = new DatagramSocket();
      InetAddress ipAddress = InetAddress.getByName("localhost");
      byte sendData[]=new byte[1024];
      byte receiveData[]=new byte[1024];
      String str=scr.nextLine();
      sendData=str.getBytes();
      DatagramPacket sendPacket = new DatagramPacket(sendData,sendData.length,ipAddress,9999);
      clientSocket.send(sendPacket);
      DatagramPacket receivePacket = new DatagramPacket(receiveData,receiveData.length);
      clientSocket.receive(receivePacket);
      String str2=new String(receivePacket.getData());
      System.out.println("From Server: "+str2);
      clientSocket.close();

   }
}