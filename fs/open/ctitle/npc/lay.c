//男塾三面拳,為ctitle npc  -CHAD-20090420

#include <ansi.h>
#include "/open/open.h"
inherit NPC;

void create()
{
    object ob;
    set_name("雷電",({"lay-dian"}));
    set("long","
男塾三面拳之一，有著招牌的八字鬍，為三面拳中知識最淵博的人，精通大往生流派。\n");
    set("gender","男性");
    set("class","fighter");
    set("combat_exp",30000000);
    set("attitude","heroism");
    set("title","" + HIW + "男塾三面拳" + NOR + "");
    set("nickname","" + HIR + "大" + HIW + "˙" + HIG + "往" + HIW + "˙" + HIC + "生" + NOR + "");
    set("no_fight",1);
    set("no_kill",1);
    set("no_plan",1);
    set("age", 25);
    set("str", 30);
    set("cor", 30);
    set("cps", 30);
    set("per", 30);
    set("int", 30);
    set("kar", 30);
    set("score",9000000);
    set("kee",10000000);
    set("max_kee",10000000);
    set("gin",10000000);
    set("max_gin",10000000);
    set("sen",10000000);
    set("max_sen",10000000);
    set("atman",10000000);
    set("max_atman",10000000);
    set("mana",10000000);
    set("max_mana",10000000);
    set("force",10000000);
    set("max_force",10000000);
    set("quest/rain",1);
    set("adv_dancer",1);
    set_skill("move",100);
    set_skill("parry",100);
    set_skill("dodge",100);
    set_temp("apply/armor",700);
    set("force_factor",10);
    set("inquiry",([
	"三面拳":"男塾三面拳為我,飛燕及月光.",
	"信物":"你非男塾三面拳之一,憑什麼跟我拿信物?",
	"大豪院邪鬼":"他是我們男塾永遠的三號生筆頭!是男塾永遠尊敬的學長!",
	"江田島平八":"男塾塾長-江田島平八!!",
	"劍桃太郎":"桃太郎啊...謎樣的人物呢,一號生筆頭非他莫屬!",
      ]));
    setup();
}

void init()
{
    ::init();
    add_action("ctitle","ctitle");
    add_action("do_answer","answer");
    add_action("do_pay","pay");
    add_action("do_reveal","reveal");
}

int do_reveal(string str)
{
    object ppl = this_player();
    object obj = this_object();
    object obj2;

    if(!str){return notify_fail("你想秀什麼?\n");}
    obj2 = present(str,ppl);
    if(!obj2){return notify_fail("...你身上沒這樣東西,想展示什麼?\n");}
    if((obj2->query("id")=="fay-mark")){
	write("你從身上拿出"+obj2->query("name")+"給"+obj->query("name")+"看，只見"+obj->query("name")+"看的入神.\n");
	call_out("msg5",0,ppl);
	return 1;}
    if((obj2->query("id")=="yua-mark")){
	write("你從身上拿出"+obj2->query("name")+"給"+obj->query("name")+"看，只見"+obj->query("name")+"看的入神.\n");
	call_out("msg6",0,ppl);
	return 1;}
    else{
	return notify_fail("你從身上拿出"+obj2->query("name")+"給"+obj->query("name")+"看,只不過"+obj->query("name")+"一點反應也沒有.\n");}
}

void greeting()
{
    object ppl = this_player();
    object obj = this_object();
    object obj2,obj3,obj4;

    if(ppl->query_temp("fay-ok")==1&&ppl->query_temp("yua-ok")==1&&!ppl->query("quests/ctitle")){
	command("say 看來你真的替我找到了我昔日的兩位同伴..自從自男塾畢業以後就斷了消息..至少知道他們都還在世上就好了!!");
	ppl->start_busy(50);
	obj2 = present("yua-mark",ppl);
	obj3 = present("fay-mark",ppl);
	obj4 = present("lay-mark",ppl);
	destruct(obj2);
	destruct(obj3);
	destruct(obj4);
	call_out("msg1",3,ppl);}
    if(ppl->query("quests/ctitle")==1){
	command("haha");
	command("say 想要回來換稱號了嗎?");
	return ;}
    if((ppl->query_temp("findfay")||ppl->query_temp("findyua"))&&(!ppl->query_temp("fay-ok")||!ppl->query_temp("yua-ok"))){
	call_out("msg4",2,ppl);
	return ;}
    else{
	command("think");}
}


int msg1()
{
    object ppl = this_player();
    object obj = this_object();

    tell_object(users(),HIY + "只聽到" + HIW + "三面拳-雷電" + HIY + "的聲音自魔界傳出：
          
          哈哈哈，" + HIW + "男塾三面拳" + HIY + "仍在世間啊!!遙想當年" + HIM + "『" + HIR + "驚天大四凶殺" + HIM + "』" + HIY + "之時，至今都過了好幾年了呀~~
          \n" + NOR);
  call_out("msg2",5,ppl);
  return 1;
}

int msg2()
{
	object ppl = this_player();
	object obj = this_object();
	
	tell_object(users(),HIY + "語畢不久，主大陸也傳來" + HIW + "三面拳-飛燕" + HIY + "的聲音：
	
	  " + HIW + "男塾三面拳" + HIY + "還一起在" + HIM + "『" + HIG + "天挑五輪大武會" + HIM + "』" + HIY + "同生共死過，此時雖各在天涯，但心卻會緊緊相隨!!
	  \n" + NOR);
	call_out("msg3",5,ppl);
	return 1;
}

int msg3()
{
	object ppl = this_player();
	object obj = this_object();
	
	tell_object(users(),HIY + "自海之王國傳來" + HIW + "三面拳-月光" + HIY + "低沉的嗓音：
	
	  此次" + HIW + "男塾-三面拳" + HIY + "能再度聚首，全得感謝 " + HIC + ""+ppl->query("name")+"" + HIY + " 的大力幫忙，往後 " + HIC + ""+ppl->query("name")+"" + HIY + " 即為三面拳的朋友，不是敵人!!

" + HIW + "三面拳-雷電" + HIY + "自魔界仰聲大嘯：
	
          哈哈哈，這次多虧了 " + HIC + ""+ppl->query("name")+" " + HIY + "，老夫就賜 " + HIC + ""+ppl->query("name")+" " + HIM + "『" + HIR + "大" + HIW + "˙" + HIG + "往" + HIW + "˙" + HIC + "生" + HIM + "』" + HIY + "的稱號，以後與 " + HIC + ""+ppl->query("name")+"" + HIY + " 為敵，即是與三面拳為敵!!
	  \n" + NOR);
	command("say 若你不喜歡此封號，可以用 ctitle 指令向我更換，但請注意，每更換一次稱號需花費與您經驗值相等的金額方可更換。");
	write("恭喜你完成男塾三面拳之謎!!\n");
	if(!ppl->query("killyar")){
	  ppl->set("title","" + HIR + "大" + HIW + "˙" + HIG + "往" + HIW + "˙" + HIC + "生" + NOR + "");
	  ppl->set("quests/ctitle",1);
	  log_file("open-area/ctitle/solve-good", sprintf("%s(%s) 得到ctitle資格 in %s\n",ppl->query("name"),ppl->query("id"), ctime(time()) ));
	  ppl->delete_temp("fay-ok");
	  ppl->delete_temp("yua-ok");
	  ppl->delete_temp("show-to-fay");
	  ppl->delete_temp("show-to-yua");
	  ppl->delete_temp("findyua");
	  ppl->delete_temp("findfay");
	  ppl->delete_temp("findok");
	  ppl->delete_busy();
	  return 1;}
	else{
	  ppl->set("quests/ctitle",1);
	  log_file("open-area/ctitle/solve-bad", sprintf("%s(%s) 得到ctitle資格但是為殺手人頭 in %s\n",ppl->query("name"),ppl->query("id"), ctime(time()) ));
	  ppl->delete_temp("fay-ok");
	  ppl->delete_temp("yua-ok");
	  ppl->delete_temp("show-to-fay");
	  ppl->delete_temp("show-to-yua");
	  ppl->delete_temp("findyua");
	  ppl->delete_temp("findfay");
	  ppl->delete_temp("findok");
	  ppl->delete_busy();
	  return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "雷電說道: hmm..你是殺手追殺的人頭，恕我不追問武林之事，你先將此事解決再談換稱號之事吧！" + NOR);}
}

int msg4()
{
		object ppl = this_player();
	  object obj = this_object();
	  object obj5;
	
   if(!ppl->query_temp("findok")){
   	ppl->set_temp("findok",1);
		command("hmm");
	  command("say "+ppl->query("name")+"該不會是遇見了我昔日的同伴們吧?");
	  obj5 = new("/open/ctitle/obj/lay-mark.c");
	  obj5 -> move(ppl);
	  write(HIY + "雷電將"+obj5->query("name")+"" + HIY + "交給了"+ppl->query("name")+" " + NOR + "\n");
	  command("say 若有朝一日，你若在遇見他們，就將這項信物給他們看，拜託你了！");
	  log_file("open-area/ctitle/laymark", sprintf("%s(%s) 從雷電這裏拿走%s in %s\n",ppl->query("name"),ppl->query("id"),obj5->query("name"), ctime(time()) ));}
	 else{
	  write("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "雷電說道: 你有再遇見他們嗎?\n" + NOR);}
}

int msg5()
{
	object ppl = this_player();
  object obj = this_object();
  
  command("hmm");
  command("say 看來你是見到" + HIW + "男塾三面拳-飛燕" + HIY + "了對吧..老友,我真想他");  
  return 1;
}

int msg6()
{
	object ppl = this_player();
  object obj = this_object();
  
  command("hmm");
  command("say 看來你是見到" + HIW + "男塾三面拳-月光" + HIY + "了對吧..老友,我真想他");  
  return 1;
}

int do_pay()
{
	object ppl = this_player();
	object obj = this_object();
	int coin;
	int i = ppl->query("combat_exp")/1000000;
	
	if(!ppl->query("quests/ctitle")){return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "雷電說道: ctitle?\n" + NOR);}
	if(i<0){return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "雷電說道: 兄弟，你的江湖資歷還太低，先沿用我大往生流的稱號，一時半載還沒人敢動你！\n" + NOR);}
	i*=1000000;
	if(!ppl->query_temp("can_ctitle")){
	if(!ppl->pay_money(i)){return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "雷電說道: 你帶的錢太少囉.\n" + NOR);}
		ppl->set_temp("can_ctitle",1);
		write("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "雷電說道: 嗯,你總共付了 "+i+" ,現在你可以輸入ctitle輸入你要的稱號了，最多可達十個中文字元長。顏色部分請 help nick。\n" + NOR);
		return 1;}return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "雷電說道: 你已經付過我錢了，現在你可以輸入ctitle輸入你要的稱號了，最多可達十個中文字元長。顏色部分請 help nick。\n" + NOR);
}

int do_answer(string str)
{
	object ppl = this_player();
	object obj = this_object();
	mixed ctitle = ppl->query_temp("ctitle");
	
	if(!ppl->query("quests/ctitle")){return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "雷電說道: 我沒問你問題啊?\n" + NOR);}
	if(!str){write("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "雷電說道: 你想更換的title為 "+ctitle+" .\n" + NOR);
		return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "雷電說道: 你是同意還是不同意呢?(answer yes or answer no).\n" + NOR);}
	if(str == "no"){
		ppl->delete_temp("ctitle");
	return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "雷電說道: 嗯，沒關係。你在輸入一次吧！\n" + NOR);}
	if(str == "yes"){
		if(!ctitle){return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "雷電說道: 你還沒輸入你要換成什麼title呢!\n" + NOR);}
		command("chat "+ppl->query("name")+"("+ppl->query("id")+") 已經將稱號更改為 "+ctitle+" .");
		ppl->set("title",ppl->query_temp("ctitle"));
		ppl->delete_temp("ctitle");
		ppl->delete_temp("can_ctitle");
		write("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "雷電說道: 好的，已將你的title更換完成。\n" + NOR);
	return 1;}
}

int ctitle(string str)
{
	object ppl = this_player();
	object obj = this_object();
	mixed ctitle1;
	
	if(!ppl->query("quests/ctitle")){return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "雷電說道: ctitle?\n" + NOR);}
	if(ppl->query_temp("can_ctitle")){
	if(!str){
		return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "雷電說道: 你想要什麼稱號呢?\n" + NOR);}
		ctitle1 = remove_color(trans_color(str));
	if(ppl->query("killyar")== 1){
	  return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "雷電說道: 在你尚未通過血的試煉之前，我是不會幫你處理的。\n" + NOR);}
        if(strlen(ctitle1)>40){
	  return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "雷電說道: 你的稱號也太長了吧！請取短一點的稱號。\n" + NOR);}
	else{
		str+=NOR;
		write("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "雷電說道: 你想更換的稱號為 "+trans_color(str)+" " + HIY + ",這稱號你同意嗎?(answer yes or no)\n" + NOR);
		ppl->set_temp("ctitle",trans_color(str));
		return 1;}
  }return notify_fail("" + HIW + "『" + HIG + "暢談" + HIW + "』" + HIY + "雷電說道: 你還沒有付錢(pay)，我不能幫你更改稱號。\n" + NOR);
}
