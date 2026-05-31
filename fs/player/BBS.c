// BBS.c
//
// 佈告欄系統，需配合 list, post, read, 等指令，請見 list 指令
// 本物件是為了減少存取硬碟而設的，是可以不要此物件。
// 物件產生時，讀入所有版面下的所有討論，以供上述命令使用
// 為了減少本物件的重複載入， post/discard/mark 等會動到檔案的命令提供函數更新
// 物件內所維護的變數
// wade@Fantasy.Space 12/16/1999
inherit ITEM;

#define BBS_DIR "/player/BBS/"
// 每個版面的最大公告數，當然，是可以超過，需使用 discard 命令清除
#define MAX_LISTS	1000
#define MAX_BOARDS	50

static mapping	boards;
static int	nob;	// number of boards

void create()
{
  string	*board,		// 所有版面
		*lists, 	// 所有佈告
		title, 		// 暫時的主題
		auth; 		// 暫時的作者
  mixed		tmp;	// 一個二維見下方說明
			// 每個元素是一個 ({ 時間，作者，保留，題目 }) 的
    int           i, j,	// 給 for 用的暫時值
		t, 	// 佈告暫時的時間值
		mark;	// 暫時的值，1 表示不可刪除

  // 取出所有的版面，是個字串
  board = get_dir (BBS_DIR);
  nob = sizeof (board);	// 版面的個數

  boards = allocate_mapping (MAX_BOARDS);

  // 某個版面的所有公告會填入一個二維空間 tmp，
  // 每個元素含 時間，作者，題目 等三個元素的
  // 我們先預給此二維記憶體
  // 這樣會比較快一些
  tmp = allocate (MAX_LISTS*2);
  for (i=0; i<sizeof (board); i++)
    tmp[i] = allocate (4);

  // 對每個版面，取出所有的公告，並分析出 ({ 時間，作者，保留，主題 }) 
  for (i=0; i<nob; i++) {
    lists = get_dir (BBS_DIR+board[i]+"/");
    for (j=0; j<sizeof (lists); j++) {
      sscanf (lists[j], "%d.%s.%d.%s", t, auth, mark, title); 
      // 如果超過 MAX_LISTS*2 則會重新配置記憶體，所以 MAX_LISTS 大一點比較好
      tmp[j] = ({ t, auth, mark, title });
    }
    // 調整正確的值進去就好, 設成物件中的資料庫
    boards[board[i]] = tmp[0..sizeof(lists)-1];
  }

  tmp = 0;	// 釋放記憶體

  setup();
}

// 傳回第 n 封佈告的檔名
string fn_list (string board, int n)
{
  return boards[board][n][0] + "." +
	 boards[board][n][1] + "." +
	 boards[board][n][2] + "." +
	 boards[board][n][3];
}

// 因為正常來說，M 是一定大於○的，所以，可以 varargs 來使用
varargs string discard (string board, int N, int M)
{
  int		i, j;	// 給 for 用的暫時變數
  mixed		lists;	// 暫時用的，因為要改動 boards[board]
  string	fn;
  
  // N, M 都沒給，就是錯的！
  if (undefinedp (M) && undefinedp (N)) return "N, M 都沒給？\n";

  if (undefinedp (boards[board]))	// 根本沒有版面 board
    return "根本沒有 " + board + " 這個版面。\n";
  lists = boards[board];

  // 我們是從 0 開始算的，所以有等號
  if (N < 0 || N >= sizeof (lists)) return "範圍不正確，請先用 list 查看。\n";
  if (!undefinedp (M)) {	// 用這種方式判斷比較保險，因為 M 可能是負的
    if (M < 0 || M >= sizeof (lists)) return "範圍不正確，請先用 list 查看。\n";
    if (M < N) return "N 比 M 大。\n";
    // 刪除 N .. M
    for (i=N; i<=M; i++) {
      fn = fn_list (board, i);
      rm (BBS_DIR+board+"/"+fn);
    }
    if (M == sizeof (lists)-1) {	// 大概是像 discard N- 之類的
      boards[board] = lists[0..N-1];
    }
    else if (N == 0) {
      boards[board] = lists[M+1..-1];	// 大概是像 discard -M 之類的
    }
    else {	// 標準的 discard N-M
      boards[board] = lists[0..N-1] + lists[M+1..-1];
    }
  }
  else {	// 參數只有 N, 也就是只刪除一封佈告
    fn = fn_list (board, N);
    rm (BBS_DIR+board+"/"+fn);
    if (N == sizeof (lists)-1) {
      boards[board] = lists[0..N-1];
    }
    else if (N == 0) {
      boards[board] = lists[1..N-1];
    }
    else {
      boards[board] = lists[0..N-1] + lists[N+1..-1];
    }
  }
  return "刪除完畢。\n";
}

// 取得所有版面列表
string *query_cat ()
{
  return keys (boards); 
}

// 查詢是否有某一版面
int if_has_board (string board)
{
  if (undefinedp (boards[board])) return 0;
  else return 1;
}

// number of lists in board
// 不做是否有 boards[board] 的檢查
int nol (string board)
{
  return sizeof (boards[board]);
}

// 計算上次存取時間 last_time 是版面佈告的第幾封
// 此處不做 boards[board] 是否存在的檢查
int query_order (string board, int last_time)
{
  int i;

  if (nol (board) > 0) {
    i = 0;
    while (last_time > boards[board][i][0]) i++;
    return i;
  }
  else return -1;
}

// 給 list 用的，類似以前的 look board，顯示目前有哪些佈告
string query_lists (string board, int N)
{
  int		i;
  string	msg;

  msg = "";
  for (i=N; i<20 && i<nol(board); i++) {
    msg = msg + sprintf ("%1s%4d:%-40s[%|10s][%19s]\n",
        boards[board][i][2] ? "m" : " ",
        i,
        boards[board][i][3][0..39],
        boards[board][i][1],
        ctime (boards[board][i][0])[0..18]);
  }
  return msg;
}

// 貼佈告，我們也不檢查是否有此版面
int post_it (
  string board,	// 選擇的版面
  string fn,	// 佈告的檔案所在
  string buf,	// 要貼的佈告內容
  int t, string auth, int mark, string title)	// 貼佈告的相關資料
{
  if (write_file (BBS_DIR+board+"/"+fn, buf, 1)) {
    boards[board] = boards[board] + ({ ({ t, auth, mark, title }) });
    return 1;
  }
}

// 讀出第 n 封佈告
int read_list (string board, int n)
{
  write (read_file (BBS_DIR+board+"/"+fn_list (board, n)));
  return 1;
}

int query_time (string board, int n)
{
  return boards[board][n][0];
}
