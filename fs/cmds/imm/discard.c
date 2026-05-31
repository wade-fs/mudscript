// discard.c
//
// 刪除佈告
// discard	刪除命令不能亂用，就幫他顯示 help() 吧！
// discard N	刪除第 N 封
// discard N-  刪除第 N 封以後的
// discard -N	刪除從頭至第 N 封
// discard N-M	刪除從 N 至 M 封
// wade@Fantasy.Space 12/16/1999
// 對於 BBS 系統的用法說明請見 help BBS

#include <BBS.h>

int help();

int main(object me, string d)
{
  string	*token;		// 字串，我們想用 explode()
  string	board;		// 正在處理的版面
  object	BBS;
  int		N, M;

  if (!d || d == "") {	// 不會用？幫他顯示 help()
    return help ();
  }

  if (!objectp (BBS = find_object (BBS_OBJ))) {	// 找不到 BBS
    write ("BBS 系統沒啟動！\n");
    return 1;
  }
  board = me->query ("post/board");
  token = explode (d, "-");	// 不知道會有什麼值？？？
  if (sizeof (token) == 2) {	// N-M 格式
    sscanf (token[0], "%d", N);
    sscanf (token[1], "%d", M);
    write (BBS->discard (board, N, M));
  }
  else if (d[0..0] == "-") {	// -M 格式
    sscanf (token[0], "%d", M);
    write (BBS->discard (board, 0, M));
  }
  else if (d[-1..-1] == "-") {	// N- 格式
    sscanf (token[0], "%d", N);
    write (BBS->discard (board, N, BBS->nol (board)));
  }
  else {			// N 格式
    sscanf (d, "%d", N);
    write (BBS->discard (board, N));
  }

  return 1;
}

int help()
{
  write(@HELP
指令格式 : discard [[N][-][M]]
意義 :
	此為 BBS 系統，命令有：
	使用者：list, select, post, read, renew
	巫　師：discard, mark, extract
指令說明：
	刪除佈告。
	discard 	太笨了，幫您顯示 本訊息。
	discard N	刪除第 N 封
	discard N-	刪除第 N 封以後的
	discard -M	刪除從頭至第 M 封
	discard N-M	刪除第 N 至 M 封
HELP
    );
    return 1;
}
