#define C_OBJ "/open/wind-rain/obj"
#define C_NPC "/open/wind-rain/npc"
#define C_ROOM "/open/wind-rain"


void greeting(object who)
{
  object me=this_object();

    if(me->query("id")=="liu-un"){    
  if((who->query("family/family_name") == "魔刀門") )
    {
       
       command("say "+who->query("name")+"你是魔刀門的人!!滅族之仇不共戴天,納命來!!");
       me->kill_ob(who);
    }
                                 }
                                 
    if( (who->query("id") == "taifar") )
    {
       command("say 歡迎總樓主!");
       command("bow "+who->query("name"));
    }
    else if( (who->query("id") == "roger") )
    {
       command("say 歡迎李樓主!");
       command("bow "+who->query("name"));
    }
//xxxx==未來武林盟主的玩家id
     else if( (who->query("id") == "juliet") )
    {
       command("say 武林盟主駕到!");
       command("bow "+who->query("name"));
    }
     else if( (who->query("id") == "chad") )
    {
       command("applaud");
       command("say 歡迎第三代總樓主-"+who->query("name")+"親臨現場參觀!!");
    }
    else
    {
     command("say 不見風雨，治世有明 ;請問下一句是什麼？");
    }
//xxx==未來對某派的格殺令
     if( (who->query("family/family_name") == "xxxx"))
    {
       
     command("say 樓主有令！對"+who->query("family/family_name")+"的人格殺勿論！ ");
     me->kill_ob(who);
    }
return;
}
