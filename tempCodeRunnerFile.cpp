
                if(ans[tear-1][ny][nx] > ans[tear][y][x]){
                        ans[tear-1][ny][nx]=ans[tear][y][x];
                        pq.push({{-ans[tear-1][ny][nx],tear-1},{nx,ny}});
                    }