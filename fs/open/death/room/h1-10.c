// Room: /open/death/room/h1-10
inherit ROOM;

void create ()
{
  set ("short", "第一殿--關卡");
  set ("long", @LONG
一座高大的城門聳立在你的面前，你想通過這兒就可以到達第二殿
；你看到門前的守衛個個長得高頭大馬，且面目極其猙獰，要通過此處
似乎十分不易。正當你苦惱要如何通過這裡時，你注意到這裡的守衛似
乎和其他地方有些不同....
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"h1-9",
]));
  set("light_up", 1);
  set("no_fight", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/guard1-10.c" : 2,
  __DIR__"action/a1-10.c" : 1,
]));
  set("no_magic", 1);

  setup();
}

        
void init() {
        add_action("do_bribe","bribe");
        }

int do_bribe(string str)
{
    if(str!="guard") 
       return notify_fail("你要把錢給誰啊!!\n");
    else {
      tell_object(this_player(),"守衛對你笑了笑說：「大爺慢走啊!」\n");
      this_player()->move(__DIR__"h2-1");  
    }
}

/*  int valid_leave(object me, string dir)
 {
        if(dir=="enter"&&present("guard",environment(me))) {
        command("kick");
        return 0;
        }
        else tell_object(this_player(),"沒有守衛的帶領，你似乎走不出這。\n");
        return 1;
}  */
