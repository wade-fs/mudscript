#include <ansi.h>
inherit NPC;
string ask_oldman();
void create ()
{
        set_name("老人",({"old man","man","old"}) );
        set("gender","男性");
        set("age",74);
        set("long","一個身處於岩壁地窖內的神祕人, 除了臉上長滿怪異的(狼斑)外, 
似乎也看不出來他與路上的乞丐有何兩樣!!\n");
	set("inquiry",([
	"狼斑":"這是(死靈骨魔)的傑作, 狼斑會讓我的\功\力全部盡失...",
	"死靈骨魔":(:ask_oldman:),
	]));
	set("chat_chance",1);
	set("chat_msg",({
	HIY"老人突然激動的喊著:天煞的死靈骨魔!! 誰能幫我報仇啊...哎哎..\n"NOR,
	HIW"老人似哭似笑的表情, 情緒十分的失控...\n"NOR,
	}));
	setup();
}

string ask_oldman()
{
object me;
me=this_player();
if(me->query_temp("ghost-hole/agree-kill-ghost",1))
return "老人高興的笑著:太好了,我期待你帶回來的好消息!!";
me->set_temp("ghost-hole/ask_oldman",1);
return "老人說著:他是掌管此地的魔神, 十分的強大, 你願意幫我報仇嗎?";
}

void init()
{
add_action("do_nod","nod");
}

int do_nod(string arg)
{
object me=this_player();
if(!arg||arg!="man")
return 0;
if(me->query_temp("ghost-hole/ask_oldman")!=1)
{
message_vision(HIY"$N對老人點頭, 老人投以懷疑的眼光看著$N\n"NOR,me);
return notify_fail("你對我點頭做什麼?");
}
message_vision(HIY"$N點頭答應了老人的要求!!\n"NOR,me);
message_vision(HIY"老人笑道:太好了, 讓我利用我最後一點\功\力把你送出這裡!!\n"NOR,me);
me->move("/open/ghost-hole/g-h04");
message_vision(HIW"空間突然出現了一個裂縫, $N從裂縫掉了下來...\n"NOR,me);
return 1;
}
