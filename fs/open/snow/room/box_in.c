#include <room.h>

inherit ROOM;

void create()
{
	set("short","密道內");
	set("long",@LONG
這是一條密道﹐這裡充滿著神秘的感覺﹐在北邊似乎有一條通道﹐
不知是通往何處﹐雪蒼派內的密秘到底是什麼呢? 前面的通道到底通到
那? 然而在石壁上有刻著﹕
      
          「入八卦迷宮陣﹐生死難料」
  
          「東西南北﹐陰陽無極﹐破乾坤」
 
LONG);
        set("exits", ([
	"north":__DIR__"room5",
	  "out":__DIR__"ducu_room_in1",
        ]) );
        setup();
}
