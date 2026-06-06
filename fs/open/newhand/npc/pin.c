//made by chad
//20090329 發放新人eq所寫

#include <ansi.h>
#include "/open/open.h"
inherit NPC;

string eqeq();
object mob = this_object();
object ppl = this_player();

void create()
{
    object ob;
    set_name("何若蘋",({"Ho rou pin","ho","pin"}));
    set("long","
她是掌管整個狂想大陸新手的新人總管，如果有任何新手有任何問題都可以向他詢問，
只是有點健忘的她不一定會記得罷了..。她似乎還有一個姊姊跟一個妹妹在狂想主大陸工作著

剛進來的新手們，如果想要[裝備]的話，可以問問看她，或\許\她會直接發放給你唷！
\n");
set("gender","女性");
set("class","dancer");
set("combat_exp",100);
set("attitude","heroism");
set("age", 19);
set("str", 90);
set("cor", 90);
set("cps", 90);
set("per", 90);
set("int", 90);
set("kar", 90);
set("no_kill",1);
set("no_fight",1);
set("score",9000000);
set("kee",100);
set("max_kee",100);
set("gin",100);
set("max_gin",100);
set("sen",100);
set("max_sen",100);
set("atman",100);
set("max_atman",100);
set("mana",100);
set("max_mana",100);
set("force",100);
set("max_force",100);
set("quest/rain",1);
set("adv_dancer",1);
set_temp("apply/armor",70);
set("get_dan_sp",1);
set("family/family_name","夜夢小築");
set("bellicosity",0);
set("title","$HIG$新人總管$NOR$");
set("nickname","$HIW$可$HIM$愛$HIW$甜$HIR$心" + NOR);
set("inquiry",([
"裝備":(: eqeq :),
]));
setup();
carry_object("/open/newhand/obj/boots.c")->wear();
carry_object("/open/newhand/obj/cloth1.c")->wear();
carry_object("/open/newhand/obj/hands.c")->wear();
carry_object("/open/newhand/obj/hat.c")->wear();
carry_object("/open/newhand/obj/legging.c")->wear();
carry_object("/open/newhand/obj/neck.c")->wear();
carry_object("/open/newhand/obj/ring-1.c")->wear();
carry_object("/open/newhand/obj/shield.c")->wear();
carry_object("/open/newhand/obj/wrists.c")->wear();
}

void greeting(object ppl)
{
  if(!ppl) return ;
		if(ppl && ppl->query("combat_exp")<350000 && ppl->query_temp("getneweq")!=1)
			{
				command("hi "+ppl->query("id"));
				command("say 你好,歡迎加入狂想空間(Fantasy Space)這個大家庭");
				command("say 我是新人總管 若蘋 (Ho rou pin),不知道有沒有缺少[裝備]呢?");
				command("say 如果需要裝備的話,可以打(ask pin about 裝備)來跟我取得裝備唷!!");
				command("say 另外可以在此處多多逛逛走走,help newbie及help可以多多使用");
				command("say 若有不懂的地方,可以用mt頻道詢問或者exp超過1500可以用chat跟大家詢問唷");

      command("say 如果還有任何問題，可以上 http://fs.twkang.net 查詢相關資訊。");          
				command("say 最後,再一次歡迎你進入狂想空間!!");
			}
			else if(ppl->query_temp("getneweq")==1)
				{
					command("addoil");
					command("say 新手EQ還好用嗎");
				}
else
			{
				command("hoho "+ ppl->query("id"));

       command("say 如果還有任何問題，可以上 http://fs.twkang.net 查詢相關資訊。");          
				command("say 老玩家都喜歡在這邊晃來晃去的,呵呵");
				return ;
			}
		
                if((ppl->query("combat_exp")<350000)&&(ppl->query("water")<200)||(ppl->query("food")<200))
			{
				command("tender");
				command("say 看你一副又累又餓的樣子,讓我幫你回復體力吧!!");
				message_vision(HIY + "
$N拿出" + HIW + "天山雪蓮" + HIY + "給了$n,只見$n吃完以後飢餓與口渴都已經回復\許\多!!\n" + NOR,mob,ppl
				);
				ppl->set("water",500);
				ppl->set("food",500);
			}
}

string eqeq()
{
	ppl=this_player();
	if(ppl->query("combat_exp")<=350000 && ppl->query_temp("getneweq")!=1)
		{
new("/open/newhand/obj/boots.c")->move(ppl);
new("/open/newhand/obj/cloth1.c")->move(ppl);
new("/open/newhand/obj/hands.c")->move(ppl);
new("/open/newhand/obj/hat.c")->move(ppl);
new("/open/newhand/obj/legging.c")->move(ppl);
new("/open/newhand/obj/neck.c")->move(ppl);
new("/open/newhand/obj/ring-1.c")->move(ppl);
new("/open/newhand/obj/shield.c")->move(ppl);
new("/open/newhand/obj/wrists.c")->move(ppl);
tell_object(environment(),HIY + "
若蘋將新手EQ交給了"+ppl->query("name")+"
\n");
command("say 來,這是你的裝備,下次上線若還需要再找我拿唷!!我在recall,newhand方向這裡!");
command("smile");
ppl->set_temp("getneweq",1);
return ;
		}
		if(ppl->query_temp("getneweq")==1)
			{
				command("think");
				command("say 你拿過一套就夠囉!!想要在拿的話等下次上線在拿唷!!");
				return ;
			}
			else
			{
				command("smirk");
				command("say 你已經不是新手囉~應該可以自己打裝備或者請老玩家幫你了,加油囉!!");
				return ;
			}
}


void init()
{
	::init();
}
