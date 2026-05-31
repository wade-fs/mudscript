//by frequency  2003/11/9
void define_att()
{
  object ob = this_object(),ewp;
  string family,attack,f_ski,ski_type;
//   if(ob->query("attribute"))   return;  //已有屬性就不再定義
  family = ob->query("family/family_name");
  if(family)
  {
   if(family == "瀧山派" || family == "火龍窟")
     {
      ob->set("attribute","fire");
      return;
     }
   if(family == "雪蒼派" || family == "極北冰原" || family == "北極圈")
     {
      ob->set("attribute","ice");
      return;
     }
   if(ob->query("class") == "beggar")
     {
      ob->set("attribute","ground");
      return;
     }
   if(family == "金刀門" || family == "射日派")
     {
      ob->set("attribute","wind");
      return;
     }
   if(family == "魔刀門" || family == "魔刀莫測" || family == "惡人谷" || family == "黑牙聯" || 
      family == "血魔一派" || family == "冥蠱魔教")
     {
      ob->set("attribute","dark");
      return;
     }
   if(family == "聖火教" || family == "天道派" || family == "仙劍派" || family == "夜夢小築" ||
      family == "銀針門" || family == "儒門")
     {
      ob->set("attribute","saint");
      return;
     }
   }  //依門判定屬性end  若仍找不到對應屬性，再以下列code判斷
    ewp = ob->query_temp("weapon");
    if(ewp)  ski_type = ewp->query("skill_type");
    else ski_type = "unarmed";
    attack = ob->query_skill_mapped(ski_type);
    if(!attack) attack = "none";
    f_ski = ob->query_skill_mapped("force");
    if(!f_ski) f_ski = "none";
    if(attack == "lungshan" || attack == "firestrike" || f_ski == "haoforce")
    {
    	ob->set("attribute","fire");
    	return;
    }
    if(attack == "snow-martial" || f_ski == "snowforce" || f_ski == "iceforce")
    {
    	ob->set("attribute","ice");
    	return;
    }
    if(attack == "pkdog-staff")
    {
    	ob->set("attribute","ground");
    	return;
    }
    if(attack == "gold-blade" || attack == "fast-blade" || attack == "god-shooting")
    {
    	ob->set("attribute","wind");
    	return;
    }
    if(attack == "badstrike" || attack == "badsword" || attack == "shadow-kill" || attack == "rain-throwing" ||
       attack == "dragon-blade" || attack == "blood_sword" || attack == "forever-love" || attack == "ming-snake" ||
       f_ski == "badforce" || f_ski == "poisonforce")
    {
    	ob->set("attribute","dark");
    	return;
    }
    if(attack == "universe" || attack == "shasword" || attack == "sun_fire_sword" || attack == "knowpen" ||
       attack == "sun_moon_sword" || f_ski == "superforce" || f_ski == "holy-force" || ob->query("class") == "bonze")
    {
    	ob->set("attribute","saint");
    	return;
    }
    if(ob->query("id") == "evil" || ob->query("id") == "ghost")
    ob->set("attribute","dark");

}
