import java.util.*;
class CRC{
	public static void main(String[] args) {
		StringBuffer dividend = new StringBuffer("11001001");//message
		StringBuffer divisor = new StringBuffer("1001");//generator
		System.out.println("Original message:"+dividend);
		System.out.println("Generator :"+divisor);
		for(int i=1;i<divisor.length();i++)
			dividend.append("0");
		StringBuffer remainder = new StringBuffer(dividend);
		remainder=divide(dividend,divisor,remainder);//get the remainder
		StringBuffer crc=new StringBuffer(merge(dividend,remainder));//generate crc code
		System.out.println("CRC code: "+crc.toString());
		StringBuffer receivedMessage=new StringBuffer(dividend);
		Random rnd =new Random();
		char ch[]={'0','1'};
		receivedMessage.setCharAt(rnd.nextInt(dividend.length()),ch[rnd.nextInt(2)]);//put some random error
		System.out.println("Message received:"+receivedMessage);
		remainder=receivedMessage;
		remainder=divide(receivedMessage,divisor,remainder);//get the remainder
		if(isZero(remainder)){
			System.out.println("Message received correctly");
		}
		else{
			System.out.println("Error Detected");
		}
	}
	static boolean isZero(StringBuffer str){
		for(int i=0;i<str.length();i++)
			if(str.charAt(i)=='1')
				return false;
		return true;	
	}
	static StringBuffer divide(StringBuffer dividend,StringBuffer divisor,StringBuffer remainder){
        int cur=0;
        while(true){
            for(int i=0;i<divisor.length();i++){
            	if(remainder.charAt(cur+i) == divisor.charAt(i))
            		remainder.setCharAt(cur+i,'0');
            	else remainder.setCharAt(cur+i,'1');
            }
            while(remainder.charAt(cur)=='0' && cur!=(remainder.length()-1))
                cur++;
            if((remainder.length()-cur)<divisor.length())
                break;
        }
        return remainder;
    }
    static StringBuffer merge(StringBuffer dividend,StringBuffer remainder){
    	for(int i=0;i<dividend.length();i++){
    		if(remainder.charAt(i)=='1')
    			dividend.setCharAt(i,'1');
    	}
    	return dividend;
    }
}