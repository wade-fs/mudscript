// Room: /d/wiz/hall1.c
#include <room.h>


inherit ROOM;
string query_long();
void create ()
{
  set ("short", "看板狀態");
  set ("long",(: query_long :));
  set("exits", ([ /* sizeof() == 6 */
  "hall" : "/open/wiz/hall1",
 ]));

set("objects",([
"/obj/bug_record.c":1,
]));
  setup();
}
void init()
{
  add_action("do_g","g");
}
int do_g(string arg)
{
  string file;
  if(!arg) return notify_fail("你要去看哪個板!");
  file = query("board/"+arg);
  write("你使用瞬間移動到目的地\n");
  this_player()->move(file);
  return 1;
}
string query_long()
{
  string str;
  object board;
  int i;
  mixed files = get_dir("/obj/board/*.c");
  str = "看板列表如下：\n";
  i = 0;
  foreach(string file in files)
  {
    if(file[0] == '.') continue;
    if(board = find_object("/obj/board/"+file))
    {
      if( this_player() ) {
        mapping notes = board->query("notes");
        int last_read_time = (int)this_player()->query("board_last_read/" + (string)(board->query("board_id")));

        if(sizeof(notes) == 0 ) continue;
        if(notes[sizeof(notes)-1]["time"] <= last_read_time ) continue;
      }
            i++;
      set("board/"+i,board->query("location"));
      str +=  "["+i+"]"+board->short() + "\n";
    }
  }
  if(i  == 0 ) str += "\n\t你沒有未讀看板。\n\n";
  str += "您可以利用 g [號碼] 來前往該板觀看。\n";
  return str;
}
