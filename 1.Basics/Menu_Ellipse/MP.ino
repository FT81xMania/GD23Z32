void MP()
{
//Menu circular
  //    (i,  a,   b,  px,  py,  r, inicial, delta)
   Parametros(4, MCa, MCb, MCX, MCY, 15, -pi, MCV);      // elipse 4 con dibujo
   Parametros(5, MCa, MCb, MCX, MCY, 15, -pi+0.9, MCV);  // elipse 5 con dibujo
   Parametros(6, MCa, MCb, MCX, MCY, 15, -pi+1.8, MCV);  // elipse 6 con dibujo    
   Parametros(7, MCa, MCb, MCX, MCY, 15, -pi+2.7, MCV);  // elipse 7 con dibujo
   Parametros(8, MCa, MCb, MCX, MCY, 15, -pi+3.6, MCV);  // elipse 8 con dibujo
   Parametros(9, MCa, MCb, MCX, MCY, 15, -pi+4.5, MCV);  // elipse 9 con dibujo
  Parametros(10, MCa, MCb, MCX, MCY, 15, -pi+5.4, MCV);  //elipse 10 con dibujo
//Menu circular
  
  while(1)
  {
    GD.ClearColorRGB(0x000000);
    GD.Clear();
    GD.get_inputs();

    GD.SaveContext();
     GD.Begin(BITMAPS);
     GD.ColorA(200);
     GD.Vertex2ii(0, 0, 15);
      
    GD.VertexTranslateX(16*DESPMCX);

       EllipseD(10,0);
       EllipseD(9,1);
       EllipseD(8,2);
       EllipseD(7,3);
       EllipseD(6,4);
       EllipseD(5,6);      
       EllipseD(4,7);      
    GD.RestoreContext();
    
    GD.SaveContext();
      STM32();
    GD.RestoreContext();
    
    GD.SaveContext();
     GD.VertexTranslateX(16*700);  GD.Tag(2);    GD.Vertex2ii(0, 400, 0);  GD.Tag(255);
    GD.RestoreContext();  

       if (GD.inputs.tag==2)
       {
        IDAsset=IDAsset+1;
        if(IDAsset>=6){IDAsset=0;}
        CargaGrupoJPG1(IDJPG);
       }
      GD.End();

//Panel izquierdo
    Poly po;   GD.ColorRGB(0x008B4B);
    GD.Tag(101);   po.begin();  po.v(16*(0+movx),16*0);                    po.v(16*(140+movx),16*0);                   po.v(16*(80+movx),16*60);                       po.v(16*(0+movx),16*60);                      po.draw(); GD.Tag(255);
    GD.Tag(102);   po.begin();  po.v(16*(0+movx),16*60+separacionpanel);   po.v(16*(80+movx),16*60+separacionpanel);   po.v(16*(80+movx),16*110);                      po.v(16*(0+movx),16*110);                     po.draw();  GD.Tag(255);   
    GD.Tag(103);   po.begin();  po.v(16*(0+movx),16*110+separacionpanel);  po.v(16*(80+movx),16*110+separacionpanel);  po.v(16*(80+movx),16*160);                      po.v(16*(0+movx),16*160);                     po.draw();  GD.Tag(255);
    GD.Tag(104);   po.begin();  po.v(16*(0+movx),16*160+separacionpanel);  po.v(16*(80+movx),16*160+separacionpanel);  po.v(16*(80+movx),16*212-(4*separacionpanel));  po.v(16*(0+movx),16*212-(4*separacionpanel)); po.draw(); GD.Tag(255);
    GD.Tag(105);   po.begin();  po.v(16*(0+movx),16*480);                  po.v(16*(140+movx),16*480);                 po.v(16*(80+movx),16*(480-60));                 po.v(16*(0+movx),16*(480-60));                po.draw();  GD.Tag(255);
  //Panel izquierdo

       if (GD.inputs.tag==105)
       {
        delay(75);
         MCV = MCV + 0.005;
       }
    
    GD.swap();
  }
}
