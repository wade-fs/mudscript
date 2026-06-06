//master of cure
//change by adam

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int time=0;

void create()
{
	set_name("扁鳩",({"Master Ben","master","ben"}) );
        set("long",
	"\n扁鵲的第四代子孫，繼承先組的遺志，廣傳醫學，
        別看他個頭小小的，被他扎上一針可就有你受的。
        緊急時需醫病(cure me)，每次一粒鑽石。\n");
	set("nickname",HIC"藥到病除"NOR);
	set("gender", "男性" );
	set("combat_exp",1000000);
	set("force"       , 4000);
	set("max_force"   , 4000);
        set("force_factor", 20);
	set("class","doctor");
        set("title","醫者工會的老大");
        set("guild_master",1);
	set_skill("unarmed",60);
	set_skill("parry",40);
	set_skill("dodge",60);
	set_skill("force", 60);
	set_skill("literate",60);
	set_skill("cure",100);
	set_skill("dagger", 60);
	set_skill("move",40);
	set_skill("poison",70);
	set_skill("throwing",90);
	
	set("inquiry", ([
	"扁鵲":"此人乃在下之先祖，為造福世人，窮盡\n
	畢生精力研究醫學，也是本門之開山始祖。\n",
	"name":"在下乃是扁鵲的第四代子孫，請多多指教.\n",
	]) );

	setup();
}

void init()
{
	add_action("do_join","join");
	add_action("do_cure","cure");
	set_heart_beat(1);
}
void heart_beat()
{
	object pill;
	if(time++ > 1000)
	{
	pill=new(CLASS_D("doctor/medicine/curesick"));
        pill->set("value", 100000);
	pill->set("medicine_power",200);
	pill->move(this_object());
	command("auc pill");
	time=0;	
	}
        :: heart_beat();
}

int do_join(string str)
{
	object me=this_player();
	if(str!=0)
	  return notify_fail("請打\"join\"即可。\n");
	if(me->query("class")=="doctor")
	return notify_fail("你不要開玩笑了，你不是早就加入了嗎？\n");
	if( me->query("class") )
	  return notify_fail("你已經加入了別的工會了\n");
	me->set("class","doctor");
/*
	printf("%s給%s一組針灸用的銀針。\n",
	this_object()->name(),me->name());
*/
	tell_object(me,"恭禧你！你已經成為醫者的一員了。\n");
	 message("system",HIC "扁鳩縱聲大笑 :\n
	 歡迎" +this_player()->name()+ "加入銀針門 !\n
	 我們醫者終於後繼有人了 !\n
	 各位夥伴們 , 讓我們一起歡迎他吧 !!\n\n"NOR,users());
	        
	
	
	return 1;
}

int do_cure(string str)
{
	object me=this_player(),ob=this_object();
	if( !str )
	return 0;

	if( str == "me" )
	{

	  if( !me->pay_money(100000000) )
	  {
	  tell_object(me,"呃～"+RANK_D->query_respect(me)+"，您帶的錢不夠，要一粒鑽石唷!!\n");
	  return 1;
	  }

	me->clear_condition();
	me->set("kee",me->query("max_kee"));
	me->set("gin",me->query("max_gin"));
	me->set("sen",me->query("max_sen"));
	me->set("eff_kee",me->query("max_kee"));
	me->set("eff_gin",me->query("max_gin"));
	me->set("eff_sen",me->query("max_sen"));
	message_vision(HIC"\n只見$N翻出壓箱的藥丸讓$n一吞，再為$n運氣行功\一番。\n"NOR,ob,me);
	message_vision(HIC"\n$n身上的傷勢和狀態都一掃而光，再度變的生龍活虎的樣子。\n"NOR,ob,me);
	return 1;
	}else{
	command("say 如果需要療傷，治療狀態，請打cure me就行了!!");
	return 1;
	}
}
