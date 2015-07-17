class Observer {
    private String name;
    public Observer(String name) {
        this.name = name;
    }
    public void update(int data) {
        System.out.println(this.name + " says: Data change to " + data + "!!");
    }
    public String getName() {
        return name;
    }
}
