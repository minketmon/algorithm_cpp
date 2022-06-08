package bj;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class 백준_2580_스도쿠 {

    static int[][] map;
    static ArrayList<Point> zero;
    static boolean complete = false;

public static void main(String[] args) throws Exception{

            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            zero = new ArrayList<Point>();
            map = new int[9][9];
            //char[] line;

            for (int i = 0; i < 9; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                //line = br.readLine().toCharArray();
                for (int j = 0; j < 9; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                    //map[i][j] = line[j] - '0';

                    // 데이터 입력 과정에서 빈 스도쿠판의 좌표를 ArrayList에 저장
                    if(map[i][j] == 0) {
                        zero.add(new Point(i,j));
                    }
                }
            }
            // 스도쿠판, ArrayList, 참조 인덱스를 인자로 넘겨준다
            dfs(0);
    }

    static void dfs(int idx) {
        // 기저조건
        if(complete) return;
        // 인덱스 값이 ArrayList의 size와 같아지면 스도쿠판 출력 후 종료
        if(idx == zero.size()) {
            complete = true;
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    System.out.print(map[i][j] + " ");
                }
                System.out.println();
            }
            return;
        }

        // 하나씩 꺼내서
        int y = zero.get(idx).y;
        int x = zero.get(idx).x;

        boolean visitRow[] = new boolean[10];
        boolean visitCol[] = new boolean[10];
        boolean visitRect[] = new boolean[10];

        // 가로
        for (int i = 0; i < 9; i++) {
            visitRow[map[y][i]] = true;
        }
        // 세로
        for (int i = 0; i < 9; i++) {
            visitCol[map[i][x]] = true;
        }
        // 사각형
        int ny = y/3 * 3;
        int nx = x/3 * 3;
        for (int i = ny; i < ny + 3; i++) {
            for (int j = nx; j < nx + 3; j++) {
                if(map[i][j] != 0) visitRect[map[i][j]] = true;
            }
        }

        // 1-9 숫자 중에 사용할 수 있는 (이미 사용된 숫자가 아닌 경우)
        for (int i = 1; i <= 9; i++) {
            if( visitRow[i] || visitCol[i] || visitRect[i]) continue;
            map[y][x] = i;
            dfs(idx + 1);
            map[y][x] = 0;
        }
    }

    // 빈 스도쿠판의 좌표가 저장 될 클래스
    static class Point{
        int y;
        int x;

    public Point(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}