
inherit NPC;
string ask_tesin();
void create()
{
        set_name("智慧老人", ({ "old man","man" }) );
	set("gender", "男性" );
        set("title","魔界村長老");
        set("age",74);
        set("str",35);
        set("cor",45);
	set("cps",25);
	set("int",15);
	set("long","村中智慧最高的長者, 滿臉的皺紋是歲月所留下的痕跡.\n");
	set("combat_exp",350);
	set("attitude", "peaceful");
        set("inquiry",([
             "龍鐵心" : (:ask_tesin:),
             "三葉仙蘭" : "聽說在妖魔古堡裡的三樓青龍室有存放這種東西.",
             "進入洞穴" : "三葉仙蘭的香氣可以克制千年冰蟾的毒氣.",
             "焚天魔王" : "聽說他自創極火金身,周身刀槍不入. 如果你打敗他的話, 也許\他會教你.  不過要小心他那毀滅性的極火三掌.",
             ]));
	set_skill("parry", 15);
        set_skill("dodge", 5);
	setup();
        add_money("coin", 25);
         	
}

string ask_tesin()
 {
if (this_player()->query("quests/shasword")==5)
{
 if (!this_player()->query_temp("find_tesin"))
  {
  this_player()->set_temp("find_tesin2",1);
  return ("龍鐵心是中原第一的鑄劍師呢..你怎麼會找到這來?。");
  }
 if (this_player()->query_temp("find_tesin")==1)
  {
  this_player()->set_temp("find_tesin2",2);
  return ("龍鐵心之前有聽說過..龍鐵心似乎幫逍遙子作了幾把威力很強的武器..不過已經不知所蹤了.");
  }
 if (this_player()->query_temp("find_tesin")==2)
  {
  this_player()->set_temp("find_tesin2",3);
  return ("早些年..有聽說過..有人來找過龍鐵心..不過不知道有沒找到就是了。");
  }
 if (this_player()->query_temp("find_tesin")==3)
  {
  this_player()->set_temp("find_tesin2",4);
  return ("龍鐵心阿..好像有人說過.他在魔域裡...不過不曉得在哪就是了。");
  }
 if (this_player()->query_temp("find_tesin")==4)
  {
  this_player()->set_temp("find_tesin2",5);
  return ("數十年前..龍鐵心曾來過這裡..但是..我不知道他現在在哪。");
  }
 if (this_player()->query_temp("find_tesin")==5)
  {
  this_player()->set_temp("find_tesin2",6);
  return ("龍鐵心來到這裡之後..曾經幫助過我們這的居民..並教我們一些基本的鑄鐵鑄劍之法。");
  }
  if (this_player()->query_temp("find_tesin")==6)
  {
  this_player()->set_temp("find_tesin2",7);
  return ("幾十年前,龍鐵心來到這裡..他身邊帶著一位小劍士..當他們在這交我們鑄造農具的技巧後,兩個人就此消失了。");
  }
}
}






