// test_officer.c
// rewrite by wade in 1/5/1996 for heart_beat 方式

#include <ansi.h>
#include <capital.h>
inherit NPC;
inherit F_MASTER;
#define PREPARE 300
#define START 330
#define END 350
#define REPORT 400

int	time=290;
mapping test_men_data = ([
            "惡魔劍寒":300,
        "漂漂玟玟":200,
	"蘇東坡": 120,
	"張載": 70,
	"王安石": 90,
	"司馬光": 100,
	"程郢": 20,
	"程顥": 80,
	"辛棄疾": 100,
	"陸九淵": 80,
	"朱熹": 110,
	"王評": 30,
	"張九": 25,
	"陳詩和": 60,
	"林賦": 65,
	"張秀豐": 70,
	"范光": 75,
	"邱育聰": 20,
	"吳擎": 80,
	"王軌": 70,
	"一頁書": 100,
	"公孫聖凡": 90,
	"歐陽離否": 80,
	"慕容常": 15,
	"慕容青": 85,
	"神秘人": 90,
	"儒影真人": 100,
	"王鳳": 70,
]);

void create()
{
	seteuid(getuid());
	set_name("嚴大人",({"test officer","officer","master"}));
	set("long","負責帝國考試的主考官,你可以用 join 來加入考試,\n"+
	           "考上的人也可用 report 來加入官職,注意: 一但加入\n"+
	           "官職,即放棄原門派,千萬慎重!!\n");
	set("gender","男性");
	set("title","主考官");
	set("age",56);
	set("time",0);
	set("test_men",([]));
	set("set_test_men",([]));
	set("new_officer",([]));
	set("test_men_id",([]));
	set("chat_chance",15);
	set("class","officer");
	set("officer_class","主考官");
	set("max_officer_power",100);
	set("officer_power",100);
	set("max_kee", 10000);
	setup();
	set_heart_beat(1);
}
void init()
{
	add_action("join_test","join");
	add_action("join_guild","report");
}

void do_prepare()
{
	CHANNEL_D->do_channel(this_object(), "mud",
	HIY "\n從京城裡傳來消息﹕\n秋試即將開始了.....\n" NOR);
}

int query_test()
{
  write ("time is "+time+".\n");
  return time;
}

void do_start()
{
	mapping	dict2;
	string	*name3;
	string	test_men_name;
	int	i;
	set("test_men_id",([]));
	CHANNEL_D->do_channel(this_object(), "mud",
	HIG "\n從京城裡傳來消息﹕\n秋試正式開始了....!!!\n" NOR);
	command("say 現在請各位要參加考試的考生開始考試(join)。");
	dict2=query("set_test_men");
	for(i=0;i<3;i++)
	{
		name3=keys(test_men_data);
		test_men_name=name3[random(sizeof(test_men_data))];
		dict2[test_men_name]=test_men_data[test_men_name];
		dict2[test_men_name]=random(random(dict2[test_men_name]));
		dict2[test_men_name]+=10+5*i;
		map_delete(test_men_data,test_men_name);
	}
	dict2=query("test_men_id");
	dict2["1"]=1;dict2["2"]=1;dict2["3"]=1;
	set("test_men_id",dict2);
}

void do_end()
{
          CHANNEL_D->do_channel(this_object(), "mud",
            HIC "\n從京裡傳來消息﹕\n秋試結束了.....\n" NOR);
          command("say 好了 ! 考試時間到了。\n");
}

void do_report()
{
	mapping dict1,dict2;
	string *name1,*name2;
	string  msg;
	string test_men_name;
	int i,th1,th2,th3;

	dict1=query("test_men");
	dict2=query("set_test_men");
	name1=keys(dict1);
	name2=keys(dict2);
	if (!name2 || sizeof(name2) == 0) return;
	th1=0;th2=0;th3=0;
	for(i=0;i<sizeof(dict2);i++)
	if(dict2[name2[i]]>dict2[name2[th1]])
		th1=i;
	if(th1==0) th2=1;
	for(i=0;i<sizeof(dict2);i++)
	if(dict2[name2[i]]>dict2[name2[th2]]&&i!=th1)
		th2=i;
	if(th1==0||th2==0) th3++;
	if((th1==1||th2==1)&&th3==1) th3++;
	for(i=0;i<sizeof(dict2);i++)
	if(dict2[name2[i]]>dict2[name2[th3]]&&i!=th1&&i!=th2)
		th3=i;
	msg = 
	    HIR"從京裡傳來的消息﹕\n秋試結果﹕.....\n狀元﹕"+
	    name2[th1]+"\n榜眼﹕"+name2[th2]+"\n探花﹕"+name2[th3]+"\n";
	msg += "落榜者﹕\n";
	for(i=0;i<sizeof(dict1);i++)
	  if(name2[th1]!=name1[i]&&name2[th2]!=name1[i]&&name2[th3]!=name1[i])
	    msg += name1[i]+"\n";
	msg += HIY "考取者請儘速來報到(report)\n" NOR;
	CHANNEL_D->do_channel(this_object(), "mud", msg);
	dict1=([]);
	dict2=query("test_men_id");
	name1=keys(query("set_test_men"));
	dict1[1]=dict2[name1[th1]];
	dict1[2]=dict2[name1[th2]];
	dict1[3]=dict2[name1[th3]];
	set("new_officer",dict1);
	set("test_men",([]));
	set("set_test_men",([]));
	time = 0;
}

int join_test()
{
	mapping dict;
	object	me=this_player();
        set_heart_beat(1);         

	if (time < START || time >= END)
		return notify_fail("秋試尚未開始﹐請你再等等吧。\n");
	if(me->query_skill("literate",1)==0)
		return notify_fail("文盲也來考試 ?\n");
        if(me->query("family/family_name")=="魔刀門") 
                return notify_fail("你所屬門派不能當官喔。\n");
if(me->query("family/family_name")=="魔刀莫測")
return notify_fail("你所屬門派不能當官喔。\n");
	dict=query("test_men");
	if(dict[me->query("name")]!=0)
		return notify_fail("你不是已經報名考試了嗎 ?\n");
	if(me->query("officer_class"))
		return notify_fail("你不當過官了嗎﹐再報名考試就是犯了欺君之罪。\n");
	message_vision(
	CYN "$N說道﹕我要參加考試 !\n" NOR,me);
	if(me->query("class")=="officer")
	{
		command("say 大人 ! 別跟我開玩笑了。");
		return 1;
	}
	command("nod");
	dict=query("test_men");
	dict[me->query("name")]=random(me->query_skill("literate",1));
	dict=query("set_test_men");
	dict[me->query("name")]=random(me->query_skill("literate",1));
	dict=query("test_men_id");
	dict[me->query("name")]=me->query("id");
	return 1;
}

int join_guild()
{
	mapping dict=query("new_officer");
	object	me=this_player();
	int i;

	if(me->query("class")=="officer")
		return notify_fail("你已經是官了。\n");
	for(i=1;i<=3;i++)
	if(me->query("id")==dict[i])
	{
		message_vision("$N考取了功\名﹐當了個小官。\n",me);
		me->set("class","officer");
		me->set("officer_class","小官");
		me->delete("family");
		me->delete("marks/仙劍七俠");
		return 1;
	}
	command("say 對不起 ! 你並沒考上﹐加油吧﹐下次再來﹐別氣餒 !!");
	return 1;
}

void heart_beat()
{
  if (time == PREPARE) do_prepare();
  else if (time == START) do_start();
  else if (time == END) do_end();
  else if (time == REPORT) do_report();

  time++;

  ::heart_beat();
}
