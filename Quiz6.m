#Least Recently Used policy 

function status = pageFaults(PageReq, nFrame)


persistent frames;


if length(frames) < nFrame
    if ismember(PageReq , frames)
        frames(frames==PageReq)=[];
        frames=[frames , PageReq];
        status = 'H';
    else 
        frames=[frames , PageReq];
        status = 'M';
    end
else
    if ismember(PageReq , frames)
        frames(frames==PageReq)=[];
        frames=[frames , PageReq];
        status = 'H';
    else
        frames(1) = [];
        frames=[frames , PageReq];
        status = 'M';
    end  
end

end