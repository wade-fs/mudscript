//by kalin
//改錯字 by blazakira 2010/10/10
inherit NPC;
string do_ask (object me);
string ask_dguger();
string ask_dguger2();
void create()
{
        set_name("小僮",({"boy"}));
        set("gender","男性");
        set("age",8);
        set("class","blademan");
        set("str",10);
        set("long","這個小孩子看起來很聰明，似乎是神算先生的好友。.\n");
        set("inquiry",([
                "神算先生" : (:ask_dguger:),
                "緣分"     : (:ask_dguger2:),
        ]));
        set("combat_exp",100);
        setup();
        add_money("silver",1);

}

int accept_fight(object who)
{
 return notify_fail("小僮哭道 : 哇 .. 媽呀。\n");
}

int accept_kill(object who)
{
 return notify_fail("小僮哭道 : 哇 .. 媽呀。\n");
}

string ask_dguger()
{//理論上用不到此判斷 因為在路觀圖上已有判斷 但是原設計者應是避免有作弊手段抵達此地 by blazakira 註解 2010/10/10
  if(!this_player()->query_temp("scholar_godplan_gi_dguger_letter")) 
    return "小僮臉上露出疑惑的表情。";
  return "神算先生就住在後面的草蘆啊，不過除非你跟他有緣分，不然先生是不會見你的。";
}

string ask_dguger2()
{//理由同上
  if(!this_player()->query_temp("scholar_godplan_gi_dguger_letter"))
    return "小僮臉上露出疑惑的表情。";
  return "有沒有緣分很難說，你就一直大叫：神算先生在嗎?  接下來就看他會不會見你囉....";
}

