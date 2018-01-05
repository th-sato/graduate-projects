writerObj = VideoWriter('Matriz2.mp4');
open(writerObj);
% writerObj.FrameRate = 60;
alpha=1;
for i=1:159
    data(alpha).matriz = importdata(['Matriz2_Incendios1000_Teste1_Estado' num2str(i) '.txt']);
    imagesc(1.+data(alpha).matriz);
    drawnow;
    pause(0.01);
    frame=getframe;
    writeVideo(writerObj, frame);
    alpha = alpha+1;
end
close(writerObj);