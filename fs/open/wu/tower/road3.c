// Room: /u/p/pokai/room/wu/road3.c
inherit ROOM;

void create()
{
  set ("short", "武威七殺塔入口");
  set ("long", @LONG
    這兒是傳說中的「武威七殺塔」，你仰頭算了算，塔高正好七層，塔身漆著像
血漬般的暗紅色，給人一種不寒而慄的感覺。  據說只有真正的武者，才夠資格進
入這個塔，但也只有最強的武者，才有機會平安的走出這個塔，並且取得武者的證
明。  你看到塔的門口站著表情肅然的老人。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"guardian" : 1,
])); 

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"road2",
  "enter" : __DIR__"tower1-1",
]));
  set("outdoors", "u");
  set("no_fight",1);
  set("no_magic",1);
  set("no_smash",1);
  set("no_dest",1);

  setup();
}

/* void init() {
	add_action("do_kill","kill");
}

int do_kill(object me , string str){
  if(present("tower older",environment(me)) && str == "older") {
    tell_object(this_player(),"守塔老人推了你一把說：去！去！去！別來鬧事！\n");
    me->move(__DIR__"road2");
    return 0;
  }
  return 1;
} 
*/

  int valid_leave(object me, string dir)
 {
        if(dir=="enter"&&present("tower older",environment(me))) {
  if (me->query("class")=="fighter")
  return 1;
  else  return notify_fail("守塔老人發覺你不是武者，阻止你進入。\n");
  }
  tell_object(this_player(),"守塔老人拍拍你肩膀，對你笑了笑。\n");
  return 1;  
}
