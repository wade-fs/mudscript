//seroom0.c
#include <ansi.h>
inherit ROOM;
string *exits=({"northdown","southdown","westdown","eastdown",
                "northwestdown","northeastdown","southwestdown","southeastdown"});
string *rooms=({"seroom1.c","seroom2.c","seroom3.c","seroom4.c",
                "seroom5.c","seroom6.c","seroom7.c","seroom8.c"});


void create ()
{
  set ("short", "地牢中庭");
  set ("long", @LONG
走了許久，你來到了地牢的中庭，中庭裡面空無一物，你唯一能看到的，
就是中庭竟然有八個出口，每個出口看起來又都一模一樣，一不小心，就會搞
混，每個出口，都是一個向下的樓梯，你開始有點擔心了，到底哪一個出口，
才可以到達地牢的底端呢？
LONG
);

  set("objects", ([ /* sizeof() == 3 */
]));
  set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"room00a",
]));
  set("light_up", -1);
  set("no_transmit",1);
  set("no_auc",1);
  set("no_clean_up",1);

  setup();
}
void init()
{
    int i,j;

    if(this_object()->query("have_set_exits")) return ;
    this_object()->set("have_set_exits",1);
    j=random(8);
    for(i=0;i<sizeof(exits);i++){
      set("exits/"+exits[i],__DIR__+rooms[j]);
      j++;
      if(j>=sizeof(rooms)) j=0;
    }
}
