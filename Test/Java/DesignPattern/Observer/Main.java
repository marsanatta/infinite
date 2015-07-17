class Main {
    public static void main (String[] args) {
        Observer o1 = new Observer("observer 1");
        Observer o2 = new Observer("observer 2");
        Observer o3 = new Observer("observer 3");
        Subject s = new Subject(100);
        s.attach(o1);
        s.attach(o3);
        s.setData(500);
        s.setData(300);
        s.detach(o3);
        s.setData(100);
        s.attach(o2);
        s.setData(125);
    }
}
