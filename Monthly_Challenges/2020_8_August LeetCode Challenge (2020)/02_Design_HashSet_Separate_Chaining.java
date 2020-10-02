class Bucket{
    private LinkedList<Integer>container;
    
    public Bucket(){
        container = new LinkedList<Integer>(); 
    }
    
    public void insert(Integer key){
        int index = this.container.indexOf(key);
        if(index == -1) this.container.addFirst(key);
    }
    
    public void remove(Integer key){
        this.container.remove(key);
    }
    
    public boolean exists(Integer key){
        int index =  this.container.indexOf(key);
        return (index != -1);
    }
}


class MyHashSet {

    private Bucket[] bucketArray;
    private int keyRange;
    
    public MyHashSet() {
        this.keyRange = 769;
        this.bucketArray = new Bucket[this.keyRange];
        for(int i=0;i<this.keyRange;i++){
            this.bucketArray[i] = new Bucket();
        }
    }
    
    protected int _hash(int key){
        return (key % this.keyRange);
    }
    
    public void add(int key) {
        int bucketIndex = this._hash(key);
        this.bucketArray[bucketIndex].insert(key);
    }
    
    public void remove(int key) {
        int index = this._hash(key);
        this.bucketArray[index].remove(key);
    }
    
    public boolean contains(int key) {
        int index = this._hash(key);
        return this.bucketArray[index].exists(key);
    }
}
