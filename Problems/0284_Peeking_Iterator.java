// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html

import java.util.NoSuchElementException;

class PeekingIterator implements Iterator<Integer> {
    
    private Iterator<Integer> iter;
    private Integer next = null;
    private boolean noSuchElem = false;
    
	public PeekingIterator(Iterator<Integer> iterator) {
	    // initialize any member here.
	    iter = iterator;
        advanceIter();
	}
    
	
    // Returns the next element in the iteration without advancing the iterator.
	public Integer peek() {
        return next;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	@Override
	public Integer next() {
	    if(noSuchElem) throw new NoSuchElementException();    
        Integer ans = next;
        advanceIter();
        return ans;
	}
	
	@Override
	public boolean hasNext() {
        return !noSuchElem;    
	}
    
    private void advanceIter(){
        if(iter.hasNext()){
            next = iter.next();
        }else{
            noSuchElem = true;
        }
    }
}