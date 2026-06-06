// by Alucard 2009/09
inherit ROOM;
#include <ansi.h>
#include <mudlib.h>
#include <command.h>
string str1,str2,str3,str4;
string get_long()
{
string str;
str = 
  "這裡就是炎日山的山頂了，四周的空氣灼熱到能將人燒傷，彷彿
身在地獄一般，眼前一片金光，什麼也看不清楚，那十顆太陽就在你
前，刺眼的光芒讓你就快失明，仔細一看，在日光中看到一個壯碩的
身影，在這炎熱的環境中絲毫不為所動，這個人一定是你尋找已久的
上古英雄后羿了。\n";
if(this_player()->query_temp("sun-down"))
{str1="";
str2="";
str3="";
str4="";
for(int i =  10 - this_player()->query_temp("sun-down") ; i >= 1;i--)
{
  str1 += RED + "＼ ∣ ／" + NOR;
  str2 += RED + "__╭╮__" + NOR;
  str3 += RED + "  ╰╯  " + NOR;
  str4 += RED + "／ ∣ ＼" + NOR;
}

str += str1+"\n"+str2+"\n"+str3+"\n"+str4+"\n" + NOR;
}
return str+"\n";

}
void create () {
        set("short","山頂");
		set("long", (: get_long :));
        set("no_auc", 1);
        set("no_transmit", 1);
		set("no_scale",1);
		set("no_chome",1);
        set("light_up",-1);
		set("outdoors", "/open/main");
        set("exits", ([
			"down" :  __DIR__"mount06",   
      ]));
	    set("objects",([ 
        __DIR__"npc/ho-yi" : 1,             
      ]));
        setup();
}
