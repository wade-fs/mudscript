inherit ROOM;
void create()
{
set("short", "兵器室入口");
set("long", @LONG
這裡是一樓殺手兵器室的唯一入口，但是居然沒有看到任何往一樓的通道？
這裡是殺手總壇，機關最多的地方，你還是不要逗留，趕快離開吧！
傳說，只有殺手有辦法熟練的發現密道，一般人很容易中機關。。。。。

LONG
);
set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ru1.c",
]));

setup();
}

void init()
{
  add_action("do_search", "search");
}

int do_search(string arg)
{
  object me=this_player();
  int max;

  if (me->query("class") != "killer" )
  {
    message_vision("$N找來找去終於發現一個開關，看來找對了。\n", me);
    message_vision("$N非常興奮的往按鈕按去，按下的那一瞬間一陣機關鳴動聲\n",me);
    message_vision("$N已經消失的無影無蹤\n", me);
    max=me->query("kee");
    max= (int) (max/2);
    me->add("kee",-max);
    tell_object(me,"一陣衝撞力將你彈飛，落入陷阱之中一直墜落。。。。。\n");
    me->move(__DIR__"firstrm.c");
    return 0;
  }
  if (!arg)
  {
    message_vision("$N熟練的操作機關，開啟一條往下的路。\n", me);
    set("exits/down", __DIR__"weaponrm.c");
    return 1;
  }
  else 
   return 0;
 }

int valid_leave(object me, string dir)
{
  int max;

  if (dir != "down") {
    this_object()->delete("exits/down");
    return 1;
  }
  if (me->query("class") != "killer")
  {
    message_vision("$N往下走去，但不小心觸動機關，瞬間一陣機關鳴動聲\n",me);
    message_vision("$N已經消失的無影無蹤\n", me);
    max=me->query("kee");
    max= (int) (max/2);
    me->add("kee",-max);
    tell_object(me,"一陣衝撞力將你彈飛，落入陷阱之中一直墜落。。。。。\n");
    me->move(__DIR__"firstrm.c");
    return 0;
  }
  if (this_object()->query("exits/"+dir)) return 1;
  else return 0;
}
