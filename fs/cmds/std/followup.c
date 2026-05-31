// followup.c 修正 by babe
//
// 本命令由 wade 改寫自 /std/bboard.c
// 原先是把本命令寫成 add_action() 所造成的命令,
// 現在搬來這兒當成普通命令.
// 增加簽名檔的使用.
// by wade in 6/30/1996
// 新增引用時，只取前、後各三行
// by wade@fs 11/14/1999
 
#include <ansi.h>
 
#define BOARD_CAPACITY query("capacity")
 
inherit F_CLEAN_UP;
 
int help(object);
 
void done_post(object me,object board,mapping note,string text)
{
  mapping last_read_time;
  string myid,reply;
  mapping *notes;
  int c;
  string sigfn,sig,id;
 
  last_read_time = me->query("board_last_read");
  myid = board->query("board_id");
  id = me->query("id");
  sigfn = sprintf ("%ssig/%s/%s.sig",DATA_DIR,id[0..0],id);
 
  if (sig = read_file (sigfn))
    note["msg"] = text + "\n--\n"+sig+NOR;
  else
    note["msg"] = text+NOR;
 
  notes = board->query("notes");
  if ( !pointerp(notes) || !sizeof(notes) )
    notes = ({ note });
  else
    notes += ({ note });
 
  // Truncate the notes if maximum capacity exceeded.
  c = board->BOARD_CAPACITY;
  if (sizeof(notes) > c)
    notes = notes[c / 2 .. c];
 
  board->set("notes",notes);
  tell_object(me,"留言完畢。\n");
 
  // Keep track which post we were reading last time.
  if ( !mapp(last_read_time) )
    me->set("board_last_read",([ myid: note["time"] ]) );
  else if (undefinedp(last_read_time[myid]) || note["time"] >
    last_read_time[myid] )
  {
    last_read_time[myid] = note["time"];
  }
 
  board->save();
  return;
}
 
void ed_exit()
{
  object board;
  mapping note;
  string fn,buf;
  string sigfn,sig,myid;
 
  board = this_player()->query_temp("post/board");
  note = this_player()->query_temp("post/note");
  fn = this_player()->query_temp("post/fn");
  this_player()->set_temp("post",0);
 
  myid = this_player()->query("id");
  sigfn = sprintf ("%ssig/%s/%s.sig",DATA_DIR,myid[0..0],myid);
  if (sig = read_file (sigfn))
    buf = read_file(fn) + "\n--\n" + sig;
  else
    buf = read_file(fn);
 
  rm (fn);
  done_post (this_player(),board,note,buf);
  buf = 0;
}
 
int	main( object me, string arg )
{
	object	board;
	mapping	*notes, note;
	int	num;
	string	note1, note2, *tmp, old_letter, op;
 
	if( !arg )
		return help( me );
	if( !board = present( "board", environment(me) ) ) 
		return notify_fail( "喂! 看清楚一點, 沒有板子, 如何回答他人的布告?\n" );
 
	if( sscanf( arg, "%s %d", op, num ) == 2 && op == "-ed")
		arg = ""+num;
	if( !sscanf( arg,"%d",num) )
		return help(me);
 
	notes = board->query("notes");
	if( num < 1 || num > sizeof(notes) )
		return notify_fail( "沒有這篇留言。\n" );
	num--;
	note = allocate_mapping(4);
	note2 = (string)notes[num]["title"]; // 取出舊信的 title
	if( note2[0..13] == HIG""HIC ) {
		note2 = note2[14..<1];
		note["title"]  = sprintf( HIG"Re:%3d"HIC" %s", num+1, note2 );
	}
	if( note2[0..9] == HIG"Re:" )
		note2 = note2[13..<1];
	if( note2[0..6] == HIC ) {
		note2 = note2[7..<1];
		note["title"]  = sprintf( HIG"Re:%3d"HIC"%s", num+1, note2 );
	}
	note["author"] = me->query("name")+"("+me->query("id")+")";
	note["time"]   = time();
     if(!notes[num]["msg"]) return 0;
	tmp = explode( notes[num]["msg"], "\n" );
	if( sizeof(tmp) > 8 ) {
		tmp = tmp[0..2] + ({ "\t\t：\t\t：" }) + tmp[<3..<1];
		old_letter = implode( tmp, "\n" );
	}
	else
		old_letter = notes[num]["msg"];

	note2 = replace_string( " 引述《" + notes[num]["author"] + "》之銘言:\n"CYN + old_letter, GRN, "" );
	note2 = replace_string( note2, NOR, "" );
	note2 = GRN + "※" + note2;
	note1 = replace_string( note2, "\n", "\n: " );
	if( note1[<2..<1] == ": " )
		note1 = note1[0..<3];
	tmp = explode( note1, "\n" );
	note1 = "";
	for( num=0; num<sizeof(tmp); num++ ) {
		if( tmp[num] == ": --")
			break;
		if( strsrch( tmp[num], ": : :") != 0 )
			note1 += tmp[num] + "\n";
	}
	tmp = 0;
	note1 += NOR;
	if( op != "-ed" )
		me->edit ( (: done_post,me,board,note :),note1 );
	else {
		note2 = "/player/edit/"+time();
		me->set_temp("post/board",board);
		me->set_temp("post/note",note);
		me->set_temp("post/fn",note2);
 		write_file (note2,note1);
		ed( note2, "ed_exit" );
	}
	return 1;
}
 
int help(object me)
{
  write(@HELP
指令格式 : followup [-ed] <數目>
 
指令說明 :
        本命令用來回布告，其中數目表示版子上的布告編號
        如果沒有 -ed，則跟以前一樣的方式，至於有 -ed
        選項的話，則以系統的編輯器回信，也就是一般巫師
        在編寫物件用的編輯器，如果您要學習使用此編輯器
        的話，請 help edit_file。
 
        本命令一定要在有版子的地方使用。
 
使用範例 :
        followup 1
        followup -ed 1
 
參考資料 :
     1. 請 help edit_file 取得說明，如果您是用 -ed 選
        項來貼布告，在貼布告時，可在冒號模式下按 h 取
        得線上說明。
     2. 此命令跟 post 類似，請 help post。
     3. 本命令可以配合簽名檔使用，請參考 sig 命令。
HELP
    );
    return 1;
}
