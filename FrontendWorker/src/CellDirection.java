
public class CellDirection {
	
	private String carType;
	private String minSpeed;
	private String maxSpeed;
	private String averageSpeed;
	
	public CellDirection(String carType, String minSpeed, String maxSpeed, String averageSpeed) {
		this.carType = carType;
		this.minSpeed = minSpeed;
		this.maxSpeed = maxSpeed;
		this.averageSpeed = averageSpeed;
	}
	
	public String getCarType(){
		return carType;
	}
	public String getMinSpeed() {
		return minSpeed;
	}
	
	public String getMaxSpeed(){
		return maxSpeed;
	}
	
	public String getAverageSpeed(){
		return averageSpeed;
	}
}
