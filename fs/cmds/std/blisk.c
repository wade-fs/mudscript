// list.c
//
// 查看佈告，預設從上次看過的開始列
// wade@Fantasy.Space 12/16/1999
// 對於 BBS 系統的用法說明請見 help()

#include <BBS.h>

int help();

int main(object me, string cat)
{
  object	BBS;
  string	title, 		// 暫時的主題
		auth, 		// 暫時的作者
		board,		// 要查看的版面
		msg;	// 用來印出訊息
  int           i, 	// 給 for 用的暫時值
		t, 	// 佈告暫時的時間值
		last_t,	// 暫時的，玩家身上的時間點
		post_n,	// 暫時的，玩家身上的第幾封
		nol,	// Number of Lists in board
		n; 	// 以現在的時間點，要往前(後)看的數目
seteuid(getuid());
  // 確定 BBS 物件
  if (!objectp (BBS = find_object (BBS_OBJ))) {
    BBS = new (BBS_OBJ);
  }
  if (!BBS) {
    write ("BBS 物件不存在！請通知巫師！\n");
    return 1;
  }
  if (cat == "cat") {	// 列出所有版面，當然可以和前面的合併判斷
    printf ("目前的版面有：%O\n", BBS->query_cat());
    return 1;
  }
  // 尚未使用 select 設定看哪一個版面
  if (undefinedp (board = me->query("post/board"))) {
    printf ("請使用 select 命令設定看哪一個版面後，再使用本命令。\n");
    return 1;
  }
  if (!BBS->if_has_board (board)) {
    write ("你選的版面錯誤！請用 select 再選擇一次。\n");
    return 1;
  }
  if (!cat) {	// 沒給參數
    n = 0;
  }
  // 語法錯誤，本來也可以設成從現在的開始列
  else if (sscanf (cat, "%d", n) != 1) {
    return help();
  }

  // 沒看過這個版面(也許是新版)
  if (undefinedp (last_t = me->query ("post/"+board))) {
    me->set("post/"+board, 0);
  }

  // 設定 看到 第幾個佈告，為了安全起見，每用一次 list 就做一次
  if (post_n = BBS->query_order (board, last_t) < 0) {	// 應該已經沒佈告了
    write ("沒任何佈告！\n");
    return 1;
  }
  me->set_temp (board, post_n);

  nol = BBS->nol (board);
  n = post_n + n;
  if (n < 0) n = 0;
  if (n > nol) n = nol;

  msg = BBS->query_lists (board, n);
  printf ("%s\n全部是 %d 封，上次看到第 %d 封。\n",
	msg, nol, post_n);

  return 1;
}

int help()
{
  write(@HELP
指令格式 : list [cat | [[+|-]數字N]
BBS 說明 :
	此為 BBS 系統，命令有：
	使用者：list, select, post, read, renew
	巫　師：discard, mark, extract
指令說明：
	查看佈告。
	list		<-- 若未使用 select 選擇看哪一個版面，則同 list cat
	list cat	<-- 列出所有版面
	list N		<-- 從起點往後跳至 N 個討論後，列出其後二十個討論
	list -N		<-- 從起點往前跳至 N 個討論後，列出其後二十個討論
HELP
    );
    return 1;
}
