function varargout = untitled(varargin)
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @untitled_OpeningFcn, ...
                   'gui_OutputFcn',  @untitled_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
function untitled_OpeningFcn(hObject, eventdata, handles, varargin)
handles.output = hObject;
guidata(hObject, handles);
set(handles.slider1 , 'enable' , 'off');
set(handles.slider2 , 'enable' , 'off');
set(handles.slider3 , 'enable' , 'off');
set(handles.slider4 , 'enable' , 'off');
set(handles.slider5 , 'enable' , 'off');
set(handles.slider6 , 'enable' , 'off');
set(handles.slider7 , 'enable' , 'off');
set(handles.slider8 , 'enable' , 'off');
global pos speed;
pos =0;
speed =0;
function varargout = untitled_OutputFcn(hObject, eventdata, handles) 
varargout{1} = handles.output;
function slider1_Callback(hObject, eventdata, handles)
ModelName = 'arm';
global var t1 t2 t3 t4 t5 ;
t1 = get(handles.slider1 , 'value');
set(handles.edit1 , 'string' , num2str(t1));
t2 = get(handles.slider2 , 'value');
set(handles.edit2 , 'string' , num2str(t2));
t3 = -get(handles.slider3 , 'value');
set(handles.edit3 , 'string' , num2str(-t3));
t4 = get(handles.slider4 , 'value');
set(handles.edit4 , 'string' , num2str(t4));
t5 = get(handles.slider5 , 'value');
set(handles.edit5 , 'string' , num2str(t5));
set_param([ModelName '/Slider Gain'],'Gain',num2str(t1))
set_param([ModelName '/Slider Gain1'],'Gain',num2str(t2))
set_param([ModelName '/Slider Gain2'],'Gain',num2str(t3))
set_param([ModelName '/Slider Gain3'],'Gain',num2str(t4))
set_param([ModelName '/Slider Gain4'],'Gain',num2str(t5))
A1 = [cosd(t1) 0 sind(t1) 0; sind(t1) 0  -cosd(t1) 0;0 1 0 165 ;0 0 0 1];
A2 = [-sind(t2), -cosd(t2), 0, -221*sind(t2); cosd(t2), -sind(t2), 0,  221*cosd(t2); 0, 0, 1, 0; 0, 0, 0, 1];
A3 = [-sind(t3), 0, cosd(t3), 0; cosd(t3), 0, sind(t3), 0; 0, 1, 0, 0; 0, 0, 0, 1];  
A4 = [cosd(t4) 0 sind(t4) 0 ; sind(t4) 0 -cosd(t4) 0; 0 1 0 222.5 ; 0 0 0 1];
A5 = [-sind(-t5), -cosd(-t5), 0, -90*sind(-t5);  cosd(-t5), -sind(-t5), 0, 90*cosd(-t5); 0, 0, 1, 0;  0, 0, 0, 1];                  
T = A1*A2*A3*A4*A5
px = round(T(1,4), 2);
py = round(T(2,4), 2);
pz = round(T(3,4), 2);
set(handles.edit9 , 'string', num2str(px));
set(handles.edit10 , 'string', num2str(py));
set(handles.edit11 , 'string', num2str(pz));
function slider1_CreateFcn(hObject, eventdata, handles)
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end
function edit1_Callback(hObject, eventdata, handles)
function edit1_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
function edit2_Callback(hObject, eventdata, handles)
function edit2_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
function edit3_Callback(hObject, eventdata, handles)
function edit3_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit4_Callback(hObject, eventdata, handles)
% hObject    handle to edit4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit4 as text
%        str2double(get(hObject,'String')) returns contents of edit4 as a double


% --- Executes during object creation, after setting all properties.
function edit4_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit5_Callback(hObject, eventdata, handles)
% hObject    handle to edit5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit5 as text
%        str2double(get(hObject,'String')) returns contents of edit5 as a double


% --- Executes during object creation, after setting all properties.
function edit5_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on slider movement.
function slider2_Callback(hObject, eventdata, handles)
ModelName = 'arm';
global var t1 t2 t3 t4 t5;

    
t1 = get(handles.slider1 , 'value');
set(handles.edit1 , 'string' , num2str(t1));
t2 = get(handles.slider2 , 'value');
set(handles.edit2 , 'string' , num2str(t2));
t3 = -get(handles.slider3 , 'value');
set(handles.edit3 , 'string' , num2str(-t3));
t4 = get(handles.slider4 , 'value');
set(handles.edit4 , 'string' , num2str(t4));
t5 = get(handles.slider5 , 'value');
set(handles.edit5 , 'string' , num2str(t5));

set_param([ModelName '/Slider Gain'],'Gain',num2str(t1))
set_param([ModelName '/Slider Gain1'],'Gain',num2str(t2))
set_param([ModelName '/Slider Gain2'],'Gain',num2str(t3))
set_param([ModelName '/Slider Gain3'],'Gain',num2str(t4))
set_param([ModelName '/Slider Gain4'],'Gain',num2str(t5))


A1 = [cosd(t1) 0 sind(t1) 0; sind(t1) 0  -cosd(t1) 0;0 1 0 165 ;0 0 0 1];
A2 = [-sind(t2), -cosd(t2), 0, -221*sind(t2); cosd(t2), -sind(t2), 0,  221*cosd(t2); 0, 0, 1, 0; 0, 0, 0, 1];
A3 = [-sind(t3), 0, cosd(t3), 0; cosd(t3), 0, sind(t3), 0; 0, 1, 0, 0; 0, 0, 0, 1];  
A4 = [cosd(t4) 0 sind(t4) 0 ; sind(t4) 0 -cosd(t4) 0; 0 1 0 222.5 ; 0 0 0 1];
A5 = [-sind(-t5), -cosd(-t5), 0, -90*sind(-t5);  cosd(-t5), -sind(-t5), 0, 90*cosd(-t5); 0, 0, 1, 0;  0, 0, 0, 1];                  
T = A1*A2*A3*A4*A5
px = round(T(1,4), 2);
py = round(T(2,4), 2);
pz = round(T(3,4), 2);

set(handles.edit9 , 'string', num2str(px));
set(handles.edit10 , 'string', num2str(py));
set(handles.edit11 , 'string', num2str(pz));




function slider2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to slider2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end


% --- Executes on slider movement.
function slider3_Callback(hObject, eventdata, handles)
ModelName = 'arm';
global var t1 t2 t3 t4 t5 ;

t1 = get(handles.slider1 , 'value');
set(handles.edit1 , 'string' , num2str(t1));
t2 = get(handles.slider2 , 'value');
set(handles.edit2 , 'string' , num2str(t2));
t3 = -get(handles.slider3 , 'value');
set(handles.edit3 , 'string' , num2str(-t3));
t4 = get(handles.slider4 , 'value');
set(handles.edit4 , 'string' , num2str(t4));
t5 = get(handles.slider5 , 'value');
set(handles.edit5 , 'string' , num2str(t5));

set_param([ModelName '/Slider Gain'],'Gain',num2str(t1))
set_param([ModelName '/Slider Gain1'],'Gain',num2str(t2))
set_param([ModelName '/Slider Gain2'],'Gain',num2str(t3))
set_param([ModelName '/Slider Gain3'],'Gain',num2str(t4))
set_param([ModelName '/Slider Gain4'],'Gain',num2str(t5))



A1 = [cosd(t1) 0 sind(t1) 0; sind(t1) 0  -cosd(t1) 0;0 1 0 165 ;0 0 0 1];
A2 = [-sind(t2), -cosd(t2), 0, -221*sind(t2); cosd(t2), -sind(t2), 0,  221*cosd(t2); 0, 0, 1, 0; 0, 0, 0, 1];
A3 = [-sind(t3), 0, cosd(t3), 0; cosd(t3), 0, sind(t3), 0; 0, 1, 0, 0; 0, 0, 0, 1];  
A4 = [cosd(t4) 0 sind(t4) 0 ; sind(t4) 0 -cosd(t4) 0; 0 1 0 222.5 ; 0 0 0 1];
A5 = [-sind(-t5), -cosd(-t5), 0, -90*sind(-t5);  cosd(-t5), -sind(-t5), 0, 90*cosd(-t5); 0, 0, 1, 0;  0, 0, 0, 1];                  
T = A1*A2*A3*A4*A5
px = round(T(1,4), 2);
py = round(T(2,4), 2);
pz = round(T(3,4), 2);

set(handles.edit9 , 'string', num2str(px));
set(handles.edit10 , 'string', num2str(py));
set(handles.edit11 , 'string', num2str(pz));

function slider3_CreateFcn(hObject, eventdata, handles)
% hObject    handle to slider3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end


% --- Executes on slider movement.
function slider4_Callback(hObject, eventdata, handles)
ModelName = 'arm';
global var t1 t2 t3 t4 t5;
t1 = get(handles.slider1 , 'value');
set(handles.edit1 , 'string' , num2str(t1));
t2 = get(handles.slider2 , 'value');
set(handles.edit2 , 'string' , num2str(t2));
t3 =- get(handles.slider3 , 'value');
set(handles.edit3 , 'string' , num2str(-t3));
t4 = get(handles.slider4 , 'value');
set(handles.edit4 , 'string' , num2str(t4));
t5 = get(handles.slider5 , 'value');
set(handles.edit5 , 'string' , num2str(t5));

set_param([ModelName '/Slider Gain'],'Gain',num2str(t1))
set_param([ModelName '/Slider Gain1'],'Gain',num2str(t2))
set_param([ModelName '/Slider Gain2'],'Gain',num2str(t3))
set_param([ModelName '/Slider Gain3'],'Gain',num2str(t4))
set_param([ModelName '/Slider Gain4'],'Gain',num2str(t5))



A1 = [cosd(t1) 0 sind(t1) 0; sind(t1) 0  -cosd(t1) 0;0 1 0 165 ;0 0 0 1];
A2 = [-sind(t2), -cosd(t2), 0, -221*sind(t2); cosd(t2), -sind(t2), 0,  221*cosd(t2); 0, 0, 1, 0; 0, 0, 0, 1];
A3 = [-sind(t3), 0, cosd(t3), 0; cosd(t3), 0, sind(t3), 0; 0, 1, 0, 0; 0, 0, 0, 1];  
A4 = [cosd(t4) 0 sind(t4) 0 ; sind(t4) 0 -cosd(t4) 0; 0 1 0 222.5 ; 0 0 0 1];
A5 = [-sind(-t5), -cosd(-t5), 0, -90*sind(-t5);  cosd(-t5), -sind(-t5), 0, 90*cosd(-t5); 0, 0, 1, 0;  0, 0, 0, 1];                  
T = A1*A2*A3*A4*A5
px = round(T(1,4), 2);
py = round(T(2,4), 2);
pz = round(T(3,4), 2);

set(handles.edit9 , 'string', num2str(px));
set(handles.edit10 , 'string', num2str(py));
set(handles.edit11 , 'string', num2str(pz));


function slider4_CreateFcn(hObject, eventdata, handles)
% hObject    handle to slider4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end


% --- Executes on slider movement.
function slider5_Callback(hObject, eventdata, handles)
ModelName = 'arm';
global var t1 t2 t3 t4 t5;

t1 = get(handles.slider1 , 'value');
set(handles.edit1 , 'string' , num2str(t1));
t2 = get(handles.slider2 , 'value');
set(handles.edit2 , 'string' , num2str(t2));
t3 = -get(handles.slider3 , 'value');
set(handles.edit3 , 'string' , num2str(-t3));
t4 = get(handles.slider4 , 'value');
set(handles.edit4 , 'string' , num2str(t4));
t5 = get(handles.slider5 , 'value');
set(handles.edit5 , 'string' , num2str(t5));

set_param([ModelName '/Slider Gain'],'Gain',num2str(t1))
set_param([ModelName '/Slider Gain1'],'Gain',num2str(t2))
set_param([ModelName '/Slider Gain2'],'Gain',num2str(t3))
set_param([ModelName '/Slider Gain3'],'Gain',num2str(t4))
set_param([ModelName '/Slider Gain4'],'Gain',num2str(t5))

A1 = [cosd(t1) 0 sind(t1) 0; sind(t1) 0  -cosd(t1) 0;0 1 0 165 ;0 0 0 1];
A2 = [-sind(t2), -cosd(t2), 0, -221*sind(t2); cosd(t2), -sind(t2), 0,  221*cosd(t2); 0, 0, 1, 0; 0, 0, 0, 1];
A3 = [-sind(t3), 0, cosd(t3), 0; cosd(t3), 0, sind(t3), 0; 0, 1, 0, 0; 0, 0, 0, 1];  
A4 = [cosd(t4) 0 sind(t4) 0 ; sind(t4) 0 -cosd(t4) 0; 0 1 0 222.5 ; 0 0 0 1];
A5 = [-sind(-t5), -cosd(-t5), 0, -90*sind(-t5);  cosd(-t5), -sind(-t5), 0, 90*cosd(-t5); 0, 0, 1, 0;  0, 0, 0, 1];                  
T = A1*A2*A3*A4*A5
px = round(T(1,4), 2);
py = round(T(2,4), 2);
pz = round(T(3,4), 2);

set(handles.edit9 , 'string', num2str(px));
set(handles.edit10 , 'string', num2str(py));
set(handles.edit11 , 'string', num2str(pz));

function slider5_CreateFcn(hObject, eventdata, handles)
% hObject    handle to slider5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
ModelName = 'arm';
open_system(ModelName);
set_param(ModelName ,'BlockReduction' ,'off');
set_param(ModelName ,'StopTime' ,'inf');

set_param(ModelName ,'StartFcn' ,'1');
set_param(ModelName ,'SimulationCommand' ,'start');

function pushbutton2_Callback(hObject, eventdata, handles)

ModelName = 'arm';
global var t1 t2 t3 t4 t5;
t1 = 0;
set(handles.edit1 , 'string' , num2str(t1));
set(handles.slider1 , 'value' , t1);
t2 = 0;
set(handles.edit2 , 'string' , num2str(t2));
set(handles.slider2 , 'value' , t2);
t3 = 0;
set(handles.edit3 , 'string' , num2str(t3));
set(handles.slider3 , 'value' , t3);
t4 = 0;
set(handles.edit4 , 'string' , num2str(t4));
set(handles.slider4 , 'value' , t4);
t5 = 0;
set(handles.edit5 , 'string' , num2str(t5));
set(handles.slider5 , 'value' , t5);

set_param([ModelName '/Slider Gain'],'Gain',num2str(t1))
set_param([ModelName '/Slider Gain1'],'Gain',num2str(t2))
set_param([ModelName '/Slider Gain2'],'Gain',num2str(t3))
set_param([ModelName '/Slider Gain3'],'Gain',num2str(t4))
set_param([ModelName '/Slider Gain4'],'Gain',num2str(t5))

A1 = [cosd(t1) 0 sind(t1) 0; sind(t1) 0  -cosd(t1) 0;0 1 0 165 ;0 0 0 1];
A2 = [-sind(t2), -cosd(t2), 0, -221*sind(t2); cosd(t2), -sind(t2), 0,  221*cosd(t2); 0, 0, 1, 0; 0, 0, 0, 1];
A3 = [-sind(t3), 0, cosd(t3), 0; cosd(t3), 0, sind(t3), 0; 0, 1, 0, 0; 0, 0, 0, 1];  
A4 = [cosd(t4) 0 sind(t4) 0 ; sind(t4) 0 -cosd(t4) 0; 0 1 0 222.5 ; 0 0 0 1];
A5 = [-sind(-t5), -cosd(-t5), 0, -90*sind(-t5);  cosd(-t5), -sind(-t5), 0, 90*cosd(-t5); 0, 0, 1, 0;  0, 0, 0, 1];                  
T = A1*A2*A3*A4*A5
px = round(T(1,4), 2);
py = round(T(2,4), 2);
pz = round(T(3,4), 2);

set(handles.edit9 , 'string', num2str(px));
set(handles.edit10 , 'string', num2str(py));
set(handles.edit11 , 'string', num2str(pz));


function edit6_Callback(hObject, eventdata, handles)
% hObject    handle to edit6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit6 as text
%        str2double(get(hObject,'String')) returns contents of edit6 as a double


% --- Executes during object creation, after setting all properties.
function edit6_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit7_Callback(hObject, eventdata, handles)
% hObject    handle to edit7 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit7 as text
%        str2double(get(hObject,'String')) returns contents of edit7 as a double


% --- Executes during object creation, after setting all properties.
function edit7_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit7 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit8_Callback(hObject, eventdata, handles)
% hObject    handle to edit8 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit8 as text
%        str2double(get(hObject,'String')) returns contents of edit8 as a double


% --- Executes during object creation, after setting all properties.
function edit8_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit8 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton3.
function pushbutton3_Callback(hObject, eventdata, handles)
close;


% --- Executes on slider movement.
function slider6_Callback(hObject, eventdata, handles)
% hObject    handle to slider6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
ModelName = 'arm';
global var;







a1 = 165;
a2 = 221;
a3 = 222.5;
a4 = 90;
Px = get(handles.slider6 , 'value');
Py = get(handles.slider7 , 'value');
Pz = get(handles.slider8 , 'value');
set(handles.edit6 , 'string' , num2str(Px));
set(handles.edit7 , 'string' , num2str(Py));
set(handles.edit8 , 'string' , num2str(Pz));


theta1 = atan2d(Py ,-Px);
O4C = Pz - a1 + a4 ;
O2C = sqrt(Px^2 +Py^2);
O2O4 = sqrt(O4C^2 +O2C^2);
x1 = (a2^2 +a3^2 - O2O4^2 )/(2*a2*a3);
theta3 = 180 - atan2d(sqrt(1 -x1^2) , x1);
peta = atan2d(O4C , O2C);
O4F = sind(theta3)*a3;
O2F = cosd(theta3)*a3;
anpha = atan2d(O4F , O2F + a2);
theta2 = (90- peta-anpha);
theta5 = 180 - theta3 - theta2;
theta4 =0;
set(handles.edit1 , 'string' , num2str(theta1));

set(handles.edit2 , 'string' , num2str(theta2));

set(handles.edit3 , 'string' , num2str(theta3));

set(handles.edit4 , 'string' , num2str(theta4));

set(handles.edit5 , 'string' , num2str(theta5));


set_param([ModelName '/Slider Gain'],'Gain',num2str(theta1));
set_param([ModelName '/Slider Gain1'],'Gain',num2str(theta2));
set_param([ModelName '/Slider Gain2'],'Gain',num2str(-theta3));
set_param([ModelName '/Slider Gain3'],'Gain',num2str(theta4));
set_param([ModelName '/Slider Gain4'],'Gain',num2str(theta5));

set(handles.slider1 , 'value' , theta1);
set(handles.slider2 , 'value' , theta2);
set(handles.slider3 , 'value' , theta3);
set(handles.slider4 , 'value' , theta4);
set(handles.slider5 , 'value' , theta5);
% Hints: get(hObject,'Value') returns position of slider
%        get(hObject,'Min') and get(hObject,'Max') to determine range of slider


% --- Executes during object creation, after setting all properties.
function slider6_CreateFcn(hObject, eventdata, handles)
% hObject    handle to slider6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end


% --- Executes on slider movement.
function slider7_Callback(hObject, eventdata, handles)
ModelName = 'arm';
global var;

a1 = 165;
a2 = 221;
a3 = 222.5;
a4 = 90;
Px = get(handles.slider6 , 'value');
Py = get(handles.slider7 , 'value');
Pz = get(handles.slider8 , 'value');
set(handles.edit6 , 'string' , num2str(Px));
set(handles.edit7 , 'string' , num2str(Py));
set(handles.edit8 , 'string' , num2str(Pz));


theta1 = atan2d(Py ,-Px);
O4C = Pz - a1 + a4 ;
O2C = sqrt(Px^2 +Py^2);
O2O4 = sqrt(O4C^2 +O2C^2);
x1 = (a2^2 +a3^2 - O2O4^2 )/(2*a2*a3);
theta3 = 180 - atan2d(sqrt(1 -x1^2) , x1);
peta = atan2d(O4C , O2C);
O4F = sind(theta3)*a3;
O2F = cosd(theta3)*a3;
anpha = atan2d(O4F , O2F + a2);
theta2 = (90- peta-anpha);
theta5 = 180 - theta3 - theta2;
theta4 =0;
set(handles.edit1 , 'string' , num2str(theta1));

set(handles.edit2 , 'string' , num2str(theta2));

set(handles.edit3 , 'string' , num2str(theta3));

set(handles.edit4 , 'string' , num2str(theta4));

set(handles.edit5 , 'string' , num2str(theta5));

set_param([ModelName '/Slider Gain'],'Gain',num2str(theta1));
set_param([ModelName '/Slider Gain1'],'Gain',num2str(theta2));
set_param([ModelName '/Slider Gain2'],'Gain',num2str(-theta3));
set_param([ModelName '/Slider Gain3'],'Gain',num2str(theta4));
set_param([ModelName '/Slider Gain4'],'Gain',num2str(theta5));


set(handles.slider1 , 'value' , theta1);
set(handles.slider2 , 'value' , theta2);
set(handles.slider3 , 'value' , theta3);
set(handles.slider4 , 'value' , theta4);
set(handles.slider5 , 'value' , theta5);


function slider7_CreateFcn(hObject, eventdata, handles)
% hObject    handle to slider7 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end


% --- Executes on slider movement.
function slider8_Callback(hObject, eventdata, handles)
ModelName = 'arm';
global var;

a1 = 165;
a2 = 221;
a3 = 222.5;
a4 = 90;
Px = get(handles.slider6 , 'value');
Py = get(handles.slider7 , 'value');
Pz = get(handles.slider8 , 'value');
set(handles.edit6 , 'string' , num2str(Px));
set(handles.edit7 , 'string' , num2str(Py));
set(handles.edit8 , 'string' , num2str(Pz));

theta1 = atan2d(Py ,-Px);
O4C = Pz - a1 + a4 ;
O2C = sqrt(Px^2 +Py^2);
O2O4 = sqrt(O4C^2 +O2C^2);
x1 = (a2^2 +a3^2 - O2O4^2 )/(2*a2*a3);
theta3 = 180 - atan2d(sqrt(1 -x1^2) , x1);
peta = atan2d(O4C , O2C);
O4F = sind(theta3)*a3;
O2F = cosd(theta3)*a3;
anpha = atan2d(O4F , O2F + a2);
theta2 = (90- peta-anpha);
theta5 = 180 - theta3 - theta2;
theta4 =0;
set(handles.edit1 , 'string' , num2str(theta1));

set(handles.edit2 , 'string' , num2str(theta2));

set(handles.edit3 , 'string' , num2str(theta3));

set(handles.edit4 , 'string' , num2str(theta4));

set(handles.edit5 , 'string' , num2str(theta5));

set_param([ModelName '/Slider Gain'],'Gain',num2str(theta1));
set_param([ModelName '/Slider Gain1'],'Gain',num2str(theta2));
set_param([ModelName '/Slider Gain2'],'Gain',num2str(-theta3));
set_param([ModelName '/Slider Gain3'],'Gain',num2str(theta4));
set_param([ModelName '/Slider Gain4'],'Gain',num2str(theta5));


set(handles.slider1 , 'value' , theta1);
set(handles.slider2 , 'value' , theta2);
set(handles.slider3 , 'value' , theta3);
set(handles.slider4 , 'value' , theta4);
set(handles.slider5 , 'value' , theta5);






function slider8_CreateFcn(hObject, eventdata, handles)
% hObject    handle to slider8 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end


% --- Executes on button press in DHT.
function DHT_Callback(hObject, eventdata, handles)


set(handles.slider1 , 'enable' , 'on');
set(handles.slider2 , 'enable' , 'on');
set(handles.slider3 , 'enable' , 'on');
set(handles.slider4 , 'enable' , 'on');
set(handles.slider5 , 'enable' , 'on');
set(handles.slider6 , 'enable' , 'off');
set(handles.slider7 , 'enable' , 'off');
set(handles.slider8 , 'enable' , 'off');



% --- Executes on button press in pushbutton5.
function pushbutton5_Callback(hObject, eventdata, handles)
global s;
    if isempty(s) || strcmp(s.Status,'closed')
        % Thi?t l?p k?t n?i
        s = serial('COM4');
        fopen(s);
        
        set(hObject, 'String', 'Disconnect');
        set(hObject,'BackgroundColor','blue');
        

    else
        % ?óng k?t n?i
        fclose(s);
        set(hObject, 'String', 'Connect');
        set(hObject,'BackgroundColor','red');
    end



function edit9_Callback(hObject, eventdata, handles)
% hObject    handle to edit9 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit9 as text
%        str2double(get(hObject,'String')) returns contents of edit9 as a double


% --- Executes during object creation, after setting all properties.
function edit9_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit9 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit10_Callback(hObject, eventdata, handles)
% hObject    handle to edit10 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit10 as text
%        str2double(get(hObject,'String')) returns contents of edit10 as a double


% --- Executes during object creation, after setting all properties.
function edit10_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit10 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit11_Callback(hObject, eventdata, handles)
% hObject    handle to edit11 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit11 as text
%        str2double(get(hObject,'String')) returns contents of edit11 as a double


% --- Executes during object creation, after setting all properties.
function edit11_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit11 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in button_send.
function button_send_Callback(hObject, eventdata, handles)
global s t1 t2 t3 t4 t5 pos speed; 
% position:{0}_Speed:{1}_Joint1:{2}_Joint2:{3}_Joint3:{4}_Joint4:{5}_Joint5:{6}_Gipper:{7}
data_to_send = sprintf('position:%d_Speed:%d_Joint1:%d_Joint2:%d_Joint3:%d_Joint4:%d_Joint5:%d_gipper:40', pos, 5, t1+100, t2+100, t3+100, t4+100, t5+100)
fprintf(s, '%s\n', data_to_send);


% --- Executes on button press in pushbutton7.
function pushbutton7_Callback(hObject, eventdata, handles)
global pos data t1 t2 t3 t4 t5 speed
pos = pos + 1;
if pos > 50
    pos = 0;
end



set(handles.edit12 , 'String' , num2str(pos));
% --- Executes on button press in pushbutton8.
function pushbutton8_Callback(hObject, eventdata, handles)
global pos
pos = pos - 1;  
if pos < 0
    pos = 50;
end
set(handles.edit12 , 'string' , num2str(pos));


function edit12_Callback(hObject, eventdata, handles)
global pos
pos = str2double(get(hObject,'String'));
function edit12_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in DHN.
function DHN_Callback(hObject, eventdata, handles)
set(handles.slider1 , 'enable' , 'off');
set(handles.slider2 , 'enable' , 'off');
set(handles.slider3 , 'enable' , 'off');
set(handles.slider4 , 'enable' , 'off');
set(handles.slider5 , 'enable' , 'off');
set(handles.slider6 , 'enable' , 'on');
set(handles.slider7 , 'enable' , 'on');
set(handles.slider8 , 'enable' , 'on');


function control_Callback(hObject, eventdata, handles)
global s
data_to_send = 'control';
fprintf(s, '%s\n', data_to_send);
function button_run_Callback(hObject, eventdata, handles)
global s
data_to_send = 'run';
fprintf(s, '%s\n', data_to_send);
function button_save_Callback(hObject, eventdata, handles)
global s
data_to_send = 'save';
fprintf(s, '%s\n', data_to_send);
function button_start_Callback(hObject, eventdata, handles)
global s
data_to_send = 'start';
fprintf(s, '%s\n', data_to_send);
function button_stop_Callback(hObject, eventdata, handles)
global s
data_to_send = 'stop';
fprintf(s, '%s\n', data_to_send);
function button_reset_Callback(hObject, eventdata, handles)
global s
data_to_send = 'reset'; 
fprintf(s, '%s\n', data_to_send);
function button_send_CreateFcn(hObject, eventdata, handles)
function pushbutton17_Callback(hObject, eventdata, handles)
ModelName = 'arm';
global var;
a1 = 165;
a2 = 221;
a3 = 222.5;
a4 = 90;
Px = -300;
Py = 0;
Pz = 70;
set(handles.edit6 , 'string' , num2str(Px));
set(handles.edit7 , 'string' , num2str(Py));
set(handles.edit8 , 'string' , num2str(Pz));


theta1 = round(atan2d(Py ,-Px));
O4C = round( Pz - a1 + a4 , 2);
O2C = sqrt(Px^2 +Py^2);
O2O4 = sqrt(O4C^2 +O2C^2);
x1 = (a2^2 +a3^2 - O2O4^2 )/(2*a2*a3);
theta3 = round(180 - atan2d(sqrt(1 -x1^2) , x1));
peta = atan2d(O4C , O2C);
O4F = sind(theta3)*a3;
O2F = cosd(theta3)*a3;
anpha = atan2d(O4F , O2F + a2);
theta2 = round((90- peta-anpha));
theta5 = 180 - theta3 - theta2;

theta4 =0;
set(handles.edit1 , 'string' , num2str(theta1));
set(handles.edit2 , 'string' , num2str(theta2));
set(handles.edit3 , 'string' , num2str(theta3));
set(handles.edit4 , 'string' , num2str(theta4));
set(handles.edit5 , 'string' , num2str(theta5));

set(handles.slider6 , 'value' , Px);
set(handles.slider7 , 'value' , Py);
set(handles.slider8 , 'value' , Pz);

set_param([ModelName '/Slider Gain'],'Gain',num2str(theta1));
set_param([ModelName '/Slider Gain1'],'Gain',num2str(theta2));
set_param([ModelName '/Slider Gain2'],'Gain',num2str(-theta3));
set_param([ModelName '/Slider Gain3'],'Gain',num2str(theta4));
set_param([ModelName '/Slider Gain4'],'Gain',num2str(theta5));
function listbox1_Callback(hObject, eventdata, handles)
ModelName = 'arm';
selected_indices = get(hObject, 'Value');
if ~isempty(selected_indices)
    selected_string = get(hObject, 'String');
    selected_item = selected_string{selected_indices(1)};
    disp(selected_item);
else
    disp('Không có m?c nào ???c ch?n.');
end
str = selected_item;
if ~endsWith(str, '_')
    str = [str '_'];
end
matches = regexp(str, ':(.*?)(?=_)', 'match');
values = cellfun(@(x) str2double(x(2:end)), matches);
if numel(values) >= 7
    position = values(1);
    speed = values(2);
    joint1 = values(3);
    joint2 = values(4);
    joint3 = values(5);
    joint4 = values(6);
    joint5 = values(7);
    
    set_param([ModelName '/Slider Gain'],'Gain',num2str(joint1));
    set_param([ModelName '/Slider Gain1'],'Gain',num2str(joint2));
    set_param([ModelName '/Slider Gain2'],'Gain',num2str(joint3));
    set_param([ModelName '/Slider Gain3'],'Gain',num2str(joint4));
    set_param([ModelName '/Slider Gain4'],'Gain',num2str(joint5));
    % Hi?n th? các giá tr?
    disp(position);
    disp(speed);
    disp(joint1);
    disp(joint2);
    disp(joint3);
    disp(joint4);
    disp(joint5);
else
    disp('Không ?? giá tr? ?? l?u vào các bi?n.');
end
function listbox1_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
function pushbutton18_Callback(hObject, eventdata, handles)
global pos data t1 t2 t3 t4 t5 speed Gipper
data{pos} = [];
data{pos} = sprintf('position:%d_Speed:%d_Joint1:%d_Joint2:%d_Joint3:%d_Joint4:%d_Joint5:%d_Gipper:%d', pos, speed, t1, t2, t3, t4, t5, Gipper);
set(handles.listbox1 , 'string', data);
function pushbutton19_Callback(hObject, eventdata, handles)
global data
data = [];
% --- Executes on slider movement.
function slider14_Callback(hObject, eventdata, handles)
global speed
speed = round(get(hObject,'Value'));
set(handles.edit14, 'string' , num2str(speed));
function slider14_CreateFcn(hObject, eventdata, handles)

if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end



function edit14_Callback(hObject, eventdata, handles)

function edit14_CreateFcn(hObject, eventdata, handles)

if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on slider movement.
function slider15_Callback(hObject, eventdata, handles)
global Gipper
Gipper = round(get(hObject , 'value' ));
set(handles.edit15 , 'String' , num2str(Gipper));

function slider15_CreateFcn(hObject, eventdata, handles)
% hObject    handle to slider15 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end



function edit15_Callback(hObject, eventdata, handles)
% hObject    handle to edit15 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit15 as text
%        str2double(get(hObject,'String')) returns contents of edit15 as a double


% --- Executes during object creation, after setting all properties.
function edit15_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit15 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
