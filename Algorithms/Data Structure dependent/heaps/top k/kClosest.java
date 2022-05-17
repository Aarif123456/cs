class Solution {
    class Point implements Comparable<Point> {
        public int x,y;
        public Point(int x, int y){
            this.x = x;
            this.y = y;
        }
        public int compareTo(Point p){
            return (int)(p.getDist() - this.getDist());
        }
        public double getDist(){
            return Math.pow(x, 2) + Math.pow(y, 2);
        }
    }

    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<Point> pq = new PriorityQueue<Point>();
        for(int[] point: points){
            Point p = new Point(point[0], point[1]);
            pq.add(p);
            if(pq.size()> k) pq.poll();
        }

        int[][] out = new int[k][2];
        while(pq.size() != 0){
            k--;
            Point p = pq.poll();
            out[k][0] = p.x;
            out[k][1] = p.y;
        }

        return out;

    }
}