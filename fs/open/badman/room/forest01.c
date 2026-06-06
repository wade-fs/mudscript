// Room: /open/badman/room/forest01.c
// written by powell 96.4.26@FS

#include "/open/open.h"

inherit ROOM;
string search_skeleton();

void create ()
{
  set ("short", "惡人森林");
  set ("long", @LONG
你走進了一大片森林之中，走著走著你才發現四周的景物似乎
一直都沒變過，讓你完全失去了方向。原來這裡就是著名的惡人森
林，據說只有惡人谷的人知道如何順利通過這片森林。

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "樹林" : "樹林中有棵樹特別其怪，好像常常受到摧殘的樣子；"+
           "你想不想也推(push)它一下啊？\n",
]));

  set("outdoors", "/open/badman");

  set("exits", ([ /* sizeof() == 4 */
  "west"  : __DIR__"forest01",
  "south" : __DIR__"forest01",
  "north" : __DIR__"forest01",
  "east"  : __DIR__"forest01",
]));

  set("search_desc", ([ /* sizeof() == 3 */
  "白骨" : (: search_skeleton :),
  "樹林" : "你發現樹林中的角落似忽有點奇怪, 你想再搜尋看看嗎?\n",
  "角落" : "你走近角落一看，赫然發現一堆白骨，\n"+
               "看來這惡人谷可真有點可怕。\n",
]));

  setup();
}


int valid_leave(object who, string dir)
{
        if( random(10)<1 ) {
                who->move(__DIR__"forest02");
                return notify_fail("");
        }
        return 1;
}

void init()
{
        add_action("do_push_tree","push");
}

string search_skeleton()
{ 
        int i ;
        i = this_player()->query_temp("search_skeleton");
     
        if (this_player()->query_temp("b_bottle") == 1)
                return
                "你不是已經找到了個青色瓶子??\n";
        else if ( i > 1) {
                new(BAD_OBJ"b_bottle")->move(this_player());
                this_player()->set_temp("b_bottle",1); 
                return 
        "經過仔細地搜尋過這些白骨後，終於在白骨堆中找到了個青色小瓶子。\n";
        }       
        else {
              this_player()->set_temp("search_skeleton",++i);
              return "你找了找，結果甚也沒找到。\n";
        } 
}

int do_push_tree(string arg)
{
        if( arg == "tree" ) {
  		new(BAD_NPC"snake-npc")->move(__DIR__"forest02");
                this_player()->move(__DIR__"forest02");
                tell_object(this_player(),
          "\n 你輕輕地向著這棵奇怪的樹推去....\n"+
            " 哇哇哇! 沒想到這樹只是個晃子，想必是掉到這惡人谷中的陷阱來了。\n"+
            " 可得小心一點應付才是...\n");
        }
        else
		tell_object(this_player(),"推推推....疑..你要推甚?\n");
        return 1;
}
