// post.c 修正 by babe
//
// 本命令由 wade 改寫自 /std/bboard.c
// 原先是把本命令寫成 add_action() 所造成的命令,
// 現在搬來這兒當成普通命令.
// 增加簽名檔的使用.
// by wade in 6/30/1996
// 修正post.exp未滿5000無法用post指令post文章!!
 
#include <ansi.h>
 
#define BOARD_CAPACITY query("capacity")
 
inherit F_CLEAN_UP;
 
int help(object);
 
void done_post(object me,object board,mapping note,string text)
{
  mapping last_read_time;
  string myid;
  mapping *notes;
  int c;
  string sigfn,sig,id;
 
  seteuid(ROOT_UID);
  last_read_time = me->query("board_last_read");
  myid = board->query("board_id");
  id = me->query("id");
  if(id=="guest") return;
  sigfn = sprintf ("%s/sig/%s/%s.sig",DATA_DIR,id[0..0],id);
 
  if (sig = read_file (sigfn))
    note["msg"] = text + "\n--\n"+sig;
  else
    note["msg"] = text;
 
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
 
  seteuid(ROOT_UID);
  board = this_player()->query_temp("post/board");
  note = this_player()->query_temp("post/note");
  fn = this_player()->query_temp("post/fn");
 
  myid = this_player()->query("id");
  sigfn = sprintf ("%s/sig/%s/%s.sig",DATA_DIR,myid[0..0],myid);
  if (sig = read_file (sigfn))
    buf = read_file(fn) + "\n--\n" + sig;
  else
    buf = read_file(fn);
  rm (fn);
  done_post (this_player(),board,note,buf);
  buf = 0;
}
 
int main(object me,string arg)
{
  mapping note;
  object  board;
  string  op,fname;
 
  if (me != previous_object()) return 0;
 
  seteuid(geteuid(me));
 
  if (!arg) return help(me);
  if (sscanf (arg,"%s %s",op,fname) == 2 && op == "-ed") arg = fname;
  else op = "";

//剛開站要給人回報bug,所以限制取消by bss
/*
  if (me->query("combat_exp") < 1100)
    return notify_fail("你的江湖歷練不足(EXP未滿1100)不能使用佈告欄，發表文章!!!\n");
*/
  if(me->query("id") == "guest")
   return notify_fail("狂想不接受,暱名post!!對狂想有意見請直接mail給大神!!\n");

  if (!board = present("board",environment(me)))
    return notify_fail( "喂! 看清楚一點, 沒有板子, 如何貼布告?\n" );
  if (board->query("wiz_post"))
   if(wizardp(me))
   sprintf("\n");
    
   else
      return notify_fail("這個佈告欄只有巫師能發表文章!!!\n");

  note = allocate_mapping(4);
  note["title"] = HIG""HIC + arg;
  note["author"] = me->query("name")+"("+me->query("id")+")";
  note["time"] = time();
 
  if (op != "-ed") me->edit( (: done_post,me,board,note :) );
  else {
    fname = "/player/edit/"+time();
    me->set_temp("post/board",board);
    me->set_temp("post/note",note);
    me->set_temp("post/fn",fname);
 
    ed (fname,"ed_exit");
  }
  return 1;
}
 
int help(object me)
{
  write(@HELP
指令格式 : post [-ed] <標題>
指令說明 :
           本命令用來貼布告，如果沒有 -ed 選項，則跟貼
         布告方式一樣，如果有 -ed 選項，則是系統提供的
         編輯器，前一種屬於舊型的方式，後一種為一般巫師
         們在編輯檔案時用的編輯器，需加 -ed，如:
           post test
           post -ed test
 
         本命令一定要在有版子的地方使用
其他參考 :
      1.請 help edit_file 取得說明，如果您是用 -ed 選
        項來貼布告，在貼布告時，可在冒號模式下按 h 取
        得線上說明。
      2.本命令跟 followup 命令類似，請 help followup。
      3. 本命令可以配合簽名檔使用，請參考 sig 命令。
HELP
    );
    return 1;
}
