string define_enemy(object enemy)
{ string force;
 int k = random(5);
 if(!enemy) return "";
 force = enemy->query_skill_mapped("force");
 if(!force)
 if(k==0) return "fire";
 else if(k==1) return "water";
 else if(k==2) return "gold";
 else if(k==3) return "wood";
 else if(k==4) return "soil";
 
 if(force == "fireforce" || force == "haoforce" || force == "holy_force"
 || force == "sunforce" || force == "loveforce" || force == "siseforce")
 return "fire";
 
 if(force == "snowforce" || force == "iceforce" || force == "poetforce" 
 || force == "fiendforce" || force == "taiyiforce")
 return "water";
 
 if(force == "shinnoforce" || force == "shaforce" || force == "dreamforce"
  || force == "superforce" || force == "poisonforce" || force == "flowerforce"
  || force == "sun_moon_force" || force == "woodforce")
 return "wood";
 
 if(force == "oneforce" || force == "powerforce" || force == "sixforce"
  || force == "dragonforce" || force == "ejinforce" || force == "followforce" || force == "papa-force")
 return "gold";
 
 if(force == "pkdog-force" || force == "badforce" || force == "gforce" || force == "blood_force" || force == "celestial" || force == "darkforce")
 return "soil";
 
 return "";
}








