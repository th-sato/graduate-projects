
public class CFS_task {
	private int niceness;
	private String name;
	private int initialTime;
	private int executiontime;
	private int executionTimeFixed;
	private int finishTime;
	private int virtualTime;
	private int timeResponse;
	private boolean finish;
	private boolean firstExecution;
	
	public CFS_task(String name, int niceness, int initialTime, int executiontime){
		this.niceness = niceness;
		this.name = name;
		this.initialTime = initialTime;
		this.executiontime = executiontime;
		this.executionTimeFixed = executiontime;
		this.finish = false;
		this.firstExecution = false;
	}

	public String getName(){
		return this.name;
	}
	
	public void setTimeResponse(int time){
		if(!this.firstExecution){
			this.firstExecution = true;
			this.timeResponse = time - this.initialTime; 
		}
	}
	
	public int getTimeResponse(){
		return this.timeResponse;
	}
	
	public void setFinishTime (int finishTime){
		this.finishTime = finishTime;
	}
	
	public int getTurnaround (){
		return (this.finishTime - this.initialTime);
	}
	
	public int getWaitTime(){
		return (this.finishTime - this.initialTime- this.executionTimeFixed);
	}
	
	
	public int getWeight(){
		return (int) (1024/(Math.pow(1.25, niceness)));
	}
	
	public int getInitialTime() {
		return initialTime;
	}

	public void updateExecutionTime(int execution){
		this.executiontime -= execution;
	}
	
	public int getExecutiontime() {
		return executiontime;
	}

	public int getVirtualTime() {
		return virtualTime;
	}

	public void setVirtualTime(int virtualTime) {
		this.virtualTime = virtualTime;
	}
	
	public void updateVirtualTime(int time) {
		this.virtualTime += time*(Math.pow(1.25, niceness));
	}
	
	public void setFinish() {
		this.finish = true;
	}
	
	public boolean getFinish() {
		return this.finish;
	}
}
