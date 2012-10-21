/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package backendtowsn;

/**
 *
 * @author Ondrej Copak
 */
public class WSNData {

    public final static byte LEFT = 0x1;
    public final static byte RIGHT = 0x0;
    
    public int cellID;
    public int nodeID;
    public byte flags;
    public long timestamp;
    public int size;
    public byte[] data;
    
    public WSNData(int cellID, int nodeID, byte flags, long timestamp, int size, byte[] data)
    {
        this.cellID = cellID;
        this.nodeID = nodeID;
        this.flags = flags;
        this.timestamp = timestamp;
        this.size = size;
        this.data = data;
    }
    
    
     public WSNData()
    {
    }
    
    @Override
     public String toString(){
        String tmp = "";
        for(int i =0;i<size;i++){
            tmp+=String.format("%x",data[i]);}
        return String.format("\ncellId: %d\n nodeId: %d\n flags: %d\n timestamp: %d\n size: %d\n data: %s\n",cellID,nodeID,flags,timestamp,size,tmp);
     }
}
