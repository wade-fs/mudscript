
inherit NPC;
						
void create()
{
	set_name("阿九一號機器人", ({ "robot 9-1","robot","9-1" }) );
	set("race", "人類");
	set("age", 30000);
	set("gender", "男性");
	
	set("chat_chance",5);
	
	set("chat_msg",({
	"Voice from Robot9-1:Everything is under control..\n",
	}));
		
	
	set("long",@TEXT
	  這是一台能幫忙檢定武器價值(value)的機器人
	  經過經密的回授及Fuzzy控制，達到每秒
	  轉65535圈的瘋狂記錄。
TEXT);	  
										
	set("attitude", "friendly");

	setup();
}
								
void init()
{ 	::init();
    	add_action("do_value","value");
}

//這是抄 chun 的 hockshop.:P							
int do_value(string arg)
{
   object ob;
   int weight,damage,i,value,t1,t2,x,y,z;
   string material;
 //  float i,value,t1,t2,x,y,z;				   
   													
   if( !arg )
   return 0;
   
   else
   {
   	if(!(ob = present(arg,this_player())) )
   	return notify_fail("你要拿甚麼給阿九一號估價?\n");
   	
   	if( ob->query("money_id") )
   	return notify_fail("R u out of ur mind?\n");
   	
   	if( ob->query("weapon_prop") == 0 )
   	return notify_fail("你肯定這東西能打人?\n");
   	
	
     	damage = ob->query("weapon_prop/damage");
   	weight = ob->query_weight();
   	material = ob->query("material");
   	t1=(weight/7);
   	t2=damage/0.25;
	x=(t1)*(t2)*0.0032;
	i=(t1)*(t2)*0.004;
        y=(t1)*(t2)*0.012;
        z=(t1)*(t2)*0.02;	
		   
	command("say"+ sprintf(" %s 重 %d ，質料是 %s ，攻擊指數 %d 。\n"
	        ,ob->short(),weight,material,damage));
																					
	switch(material)
	{
	 case "iron" : value = x;
	 	       break;
	 case "steel" : value = i;
	 		break;
	 case "ironsteel" : value = y; 
	 		    break;
   	 case "crimsonsteel" : value = z;
   	 		    break;
        }
						
	command("say 公定價錢是...");
        command("say"+ sprintf(" %d \n",value));
        return 1;
								
	
//	if( material == "iron" )
//	value = (int)(i*0.8);
//	sprintf("阿九一號 > 這玩意公定value %d 加減30%都可接受 \n",value);
//	return 1;

//	if( material == "steel" )
//	value = i; 
//        sprintf("阿九一號 > 這玩意公定value %d 加減30%都可接受 \n",value);
//        return 1;
												                        
//	if( material == "ironsteel" )
//	value = i*3;
//	sprintf("阿九一號 > 這玩意公定value %d 加減30%都可接受 \n",value);
//	return 1;
	        
//	if( material == "crimsonsteel" )
//	value = i*5;
//	sprintf("阿九一號 > 這玩意公定value %d 加減30%都可接受 \n",value);
//	return 1;
  }        
}
