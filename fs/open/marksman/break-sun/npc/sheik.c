//sheik.c
#include <ansi.h>
inherit NPC;
string sun7();
string sun8();
void create()
{
	set_name("村長",({"sheik"}) );
	set("long","雖然貴為一村長，但長年為村民艱苦的生活所困擾，因此看起來比實際年齡蒼老許\多。\n");
	set("gender","男性");
	set("age",47);
	set("combat_exp", 98);
	set("inquiry",([
	"困擾":(: sun7 :),
	"壯年人":(: sun8 :),
	]));
	setup();
}

string sun7()
{
 object me = this_player();
 int k;
 k = me->query_temp("ask-break-sun");
 if(!me) return"";
 if(me->query("family/family_name") != "射日派") return "聽不懂啦!!";
 if(k>6) return "本村有個猛男!!";
 if(me->query("break-sun")) return "你已經幫我解決啦!!";
 if(!k || k<6) return "我沒有困擾啊!!";
 else {
       command("sigh");
       command("say 
這個村子已經三年沒下雨了......你看，天上竟然有十顆太陽，實在為我們帶來不少
煩惱，村子裡住著一個壯年人，射箭技術非常高明，自稱可以射下太陽，只是我看他
的箭可能還沒碰到太陽就被燒毀了，真是異想天開。");
       me->set_temp("ask-break-sun",7);
      }
  return "";
}

string sun8()
{
 object me = this_player();
 int k;
 k = me->query_temp("ask-break-sun");
 if(!me) return"";
 if(me->query("family/family_name") != "射日派") return "聽不懂啦!!";
 if(k>7) return "山上!!";
 if(me->query("break-sun")) return "他喜歡在山上看風景!!";
 if(!k || k<7) return "山上!!";
 else {
       command("think");
       command("say 他可能又在山頂上發神經了吧，你去勸勸他吧！");
       me->set_temp("ask-break-sun",8);
      }
  return "";
}
