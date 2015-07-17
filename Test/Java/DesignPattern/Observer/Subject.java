import java.util.ArrayList;

class Subject {
    private int data;
    private ArrayList<Observer> list = new ArrayList<Observer>();

    public void attach(Observer o) {
        System.out.println("attach " + o.getName());
        list.add(o);
    }
    
    public void detach(Observer o) {
        System.out.println("detach " + o.getName());
        list.remove(o);    
    }
    
    public Subject(int data) {
        this.data = data;
    }
    
    public void notifyObservers(){
        for (Observer o : list) {
            o.update(this.data);
        }
    }

    public void setData(int data) {
        this.data = data;
        notifyObservers();
    }
}
