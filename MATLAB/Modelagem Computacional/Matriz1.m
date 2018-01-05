% alpha=1;
% for i=1:126
%     data(alpha).matriz = importdata(['Matriz1_Incendios1000_Teste1_Estado' num2str(i) '.txt']);
%     mymap = [0 1 0; 0 0 1; 1 0 0; 0 0 0; 1 1 0];
%     imagesc(1.+data(alpha).matriz);
%     drawnow;
%     pause(0.1);
%     alpha = alpha+1;
% end

writerObj = VideoWriter('Matriz1.mp4');
open(writerObj);
% writerObj.FrameRate = 60;
alpha=1;
for i=1:126
    data(alpha).matriz = importdata(['Matriz1_Incendios1000_Teste1_Estado' num2str(i) '.txt']);
    imagesc(1.+data(alpha).matriz);
    drawnow;
    pause(0.01);
    frame=getframe;
    writeVideo(writerObj, frame);
    alpha = alpha+1;
end
close(writerObj);