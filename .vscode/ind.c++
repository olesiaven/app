void detour::DFS(int start)
{
                    int dfs = 0;
                    Stack stack;

                    visited[start] = true;
                    dfsnumber[start] = ++dfs;
                    stack.Push(start);

                    while(stack.first)
                    {
                        for(int i=0; i<size; i++)
                        {
                            if((graph[stack.first->data][i]) && !(visited[i]))
                            {
                                visited[i] = true;
                                dfsnumber[i] = ++dfs;
                                stack.Push(i);
                            }
                        }

                        stack.Pop();

                    }
}