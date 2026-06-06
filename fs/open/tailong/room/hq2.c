inherit ROOM;

void create ()
{
  set ("short", "地底密室");
  set ("long", @LONG
完全沒有光線的密室，但是空氣卻不會很悶，空間狹小
可以看得出來是被人隨便弄出來的。
你看了看，除了回到另一間密室以外，好像沒有別的出路

LONG);

  set("exits", ([
  "south" : __DIR__"hq1",
]));
  set("objects",([
  "/open/tailong/npc/sp_girl" : 1,
]));
  set("no_magic",1);
  set("no_kill",1);
  set("no_fight",1);
  set("no_transmit",1);

  setup();
}

int close_out ()
{
  delete("exits/out");
  return 1;
}

int valid_leave(object who,string dir){
  if(dir=="out") {
    call_out("close_out",3);
  }
  return :: valid_leave(who,dir);
}

