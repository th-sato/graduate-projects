
public class CFS_RQ {
	private final int sched_latency_ns = 20;
	private final int sched_min_granularity_ns = 4;
	private int real_time;
	private int time_slice;
	private int period;
	private int totalTWRQ; //total weight of tasks in the run queue
	private int counterTimeSlice;
	private CFS_task [] tasks;
	private CFS_task runningTask;
	private RB_Root rbt;
	private boolean first;
	private double throughput;
	
	public CFS_RQ(CFS_task [] tasks){
		this.rbt = new RB_Root();
		this.tasks = tasks;
		this.real_time = 0;
		this.time_slice = 0;
		this.runningTask = null;
		this.counterTimeSlice = 0;
		this.first = true;
		this.throughput = 0;
	}
	
	private void calculateTimeSlice (int taskWeight){
		calculatePeriod();
		this.time_slice = this.period*(taskWeight/this.totalTWRQ);
		if(this.time_slice < sched_min_granularity_ns)
			this.time_slice = sched_min_granularity_ns;
		
	}
	
	private void calculatePeriod(){
		if(rbt.getNumber() > (this.sched_latency_ns/this.sched_min_granularity_ns))
			this.period = this.sched_latency_ns * this.sched_min_granularity_ns;
		else
			this.period = sched_latency_ns;
	}
	
	private boolean theTasksCompleted (){
		for (int i=0; i<this.tasks.length; i++){
			if(!this.tasks[i].getFinish())
				return false;
		}
		return true;
	}
	
	private void updateVirtualTime(CFS_task task){
		task.updateVirtualTime(this.time_slice);
	}
	
	private void addVirtualTimeRBT(CFS_task task){
		task.setVirtualTime(0);
	}
	
	private void addRunningTask(){
		this.runningTask = rbt.getLowestValue();
		this.runningTask.setTimeResponse(this.real_time);
		calculateTimeSlice(this.runningTask.getWeight());
		rbt.deleteNodeByTask(this.runningTask);
		this.totalTWRQ -= this.runningTask.getWeight();
		if(this.time_slice >= this.runningTask.getExecutiontime())
			this.time_slice = this.runningTask.getExecutiontime();
		this.counterTimeSlice = 0;
		System.out.print(this.real_time+": ");
		System.out.println(this.runningTask.getName());
	}
	
	private void executionScheduler(){
		if(this.first){
			if(!this.rbt.isEmpty()){
				this.first = false;
				addRunningTask();
			}
		}
		else if(this.counterTimeSlice >= this.time_slice){
			this.runningTask.updateExecutionTime(this.time_slice);
			if(this.runningTask.getExecutiontime() <= 0){
				this.runningTask.setFinishTime(this.real_time-1);
				this.runningTask.setFinish();
				System.out.println(this.runningTask.getName() + " Completo");
			}
			else{
				updateVirtualTime(this.runningTask);
				rbt.insertNodeByTask(this.runningTask);
				this.totalTWRQ += this.runningTask.getWeight();
			}
			if(!this.rbt.isEmpty())
				addRunningTask();
		}
		else{
			this.counterTimeSlice++;
		}
		
	}
	
	private void calculateThroughput(){
		this.throughput = (double) tasks.length/this.real_time;
	}
	
	public double getThroughput(){
		return this.throughput;
	}
	
	public void startScheduler(){
		this.real_time = 0;
		while(!theTasksCompleted()){
			for (int i=0; i<tasks.length; i++){
				if(this.tasks[i].getInitialTime() == this.real_time){
					addVirtualTimeRBT(tasks[i]);
					this.rbt.insertNodeByTask(tasks[i]);
					this.totalTWRQ += tasks[i].getWeight(); 
				}
			}
			executionScheduler();
			this.real_time++;
		}
		calculateThroughput();
	}
	
	public CFS_task [] returnTasks(){
		return tasks;
	}
}