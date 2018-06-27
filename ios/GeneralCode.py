#coding:utf-8

import os
import sys
import random
import time
# from selector import Selector


reload(sys)
sys.setdefaultencoding('utf8')

class Selector:
	Param = [u'Base', u'Macro', u'Kit', u'Object', u'Archiver', u'Time', u'Bundle', u'Thread', u'color', u'Image', u'Control', u'Button', u'Gesture', u'View', u'Scroll', u'Table', u'Bar', u'Item', u'Text', u'Field', u'Screen', u'Device', u'Application', u'Font', u'Player', u'Utility', u'Class', u'Info', u'Cache', u'Memory', u'Disk', u'Frame', u'Sprite', u'Sheet', u'Animated', u'Manager', u'Default', u'Label', u'Attribute', u'Parser', u'Delegate', u'Compontent', u'Selection', u'Keyboard', u'Hash', u'Keychain', u'Transaction', u'Dispatch', u'Safe', u'Global', u'Define', u'Login', u'Play', u'Regist', u'Home', u'Channel', u'Price', u'Model', u'Order', u'Role', u'Group', u'Name', u'Level', u'Data', u'Account', u'Copyright', u'Favorite', u'Shared', u'OffLine', u'Download', u'Patcher', u'Setting', u'Top', u'Bottom', u'Left', u'Right', u'Alert', u'TabItem', u'SongList', u'Header', u'Lyric', u'BaseInfo', u'UserInfo', u'RoleInfo', u'GroupInfo', u'ProductInfo', u'ChannelInfo', u'NetworkInfo', u'Tool', u'Social', u'Push', u'Notifications', u'User', u'Pay', u'IAP', u'OnLine', u'Password', u'Signer', u'Logout', u'Share', u'obstacle' , u'Most', u'Most', u'Car' , u'Totorial', u'Count', u'Refer', u'Anything' , u'Make', u'Difficult', u'College', u'Tutor', u'Professor', u'Method', u'Type', u'Book' , u'Especially', u'University', u'Student', u'Guidance', u'clash', u'Abstract', u'Idea', u'think', u'based', u'general', u'Than', u'rather', u'real', u'event', 'start', u'stop', u'pause', u'run', u'running', 'begin', u'end', u'question', u'concept', u'justice', u'grammar', u'Quality', u'verbose', u'concatenation', u'auxiliary', u'seal', u'synopsis', u'entitlement', u'distinguish', u'encryption', u'authority', u'security', u'provision']

class MethodType:
	ClassMethod = u'ClassMethod'
	InstanceMehod = u'InstanceMethod'

class Params(object):
	"""docstring for Params"""

	StrongType = [ u'NSDictionary', u'NSMutableDictionary', u'NSMutableArray', u'NSArray', u'UIView', u'UITableView', u'UIButton' , u'UIImage' , u'UIImageView']
	CopyType = [u'NSString', u'NSMutableString',]
	Type = StrongType + CopyType

	@classmethod
	def GetType(cls, item):
		if item in cls.StrongType:
			return u'strong'
		elif item in cls.CopyType:
			return u'copy'
		else:
			return None

	def __init__(self, param_name, param_type):
		super(Params, self).__init__()
		self.param_name = param_name
		self.param_type = param_type
		if not param_type in self.__class__.Type:
			raise Exception(u'param type error, type = {0}'.format(param_type))

	def name(self):
		return self.param_name

	def type(self):
		return self.param_type

class GeneralObject(object):
	"""Base Class for General Object"""
	def __init__(self):
		super(GeneralObject, self).__init__()

	def general_params(self, models = None):
		""" 
		automatic general some params,
		models: to choice one of the param for the `models`, must be a list, default is None
		"""
		if models is None or not isinstance(models, list):
			models = ['roleName', 'roleID', 'groupName', 'groupID', 'desc', 'info', 'price', 'order', 'name']
		return random.choice(models)

	def general_int(self, max_num=10):
		return random.randint(1,max_num)

	def general_choice(self, choice):
		if not isinstance(choice, list):
			raise Exception(u'the choice is not the list, choice = {0}'.format(choice))
		return random.choice(choice)

	def general_from_list(self, choice, num=1):
		ret = ""
		for x in range(num):
			if x != num -1:
				ret = ret + self.general_choice(choice) + "_"
			else:
				ret = ret + self.general_choice(choice)
		return ret

	def general_capital_string(self, num = 1):
		model = "ABCDEFGHIGKLMNOPQRSTUVWXYZ"
		if num <= 1:
			num = 1
		s = ""
		for index in xrange(0,num):
			s += "".join(random.sample(model, 1))
		return s

	def general_lowercase_string(self, num):
		model = "abcdefghijklmnopqrstuvwxyz"
		if num <= 1:
			num = 1
		s = ""
		for index in xrange(0,num):
			s += "".join(random.sample(model, 1))
		return s

	def general_string(self, num = 8):
		if num < 1:
			return
		elif num == 1:
			return self.general_capital_string()
		else:
			return self.general_capital_string(1) + self.general_lowercase_string(num - 1)
		
class GeneralMethod(GeneralObject):
	
	def __init__(self, name, param_list = [], return_type = None , method_type = MethodType.InstanceMehod):
		""" 
		name: the method's name
		param_list: the params list , each element is `Params`
		return_type: the method's return value type
		method_type: the method type , class method or instance method
		"""
		super(GeneralObject, self).__init__()
		self.name = name
		self.param_list = param_list
		if return_type is None:
			return_type = u'void'
		self.return_type = return_type
		self.method_type = method_type
		
	def _general_head(self):
		method = "-"
		if self.method_type == MethodType.ClassMethod:
			method = "+"
		method = method + " (" + self.return_type + ")" + self.name

		for param in self.param_list:
			if not isinstance(param, Params):
				return ""
			name = param.name()
			name_type = param.type()
			symbol = " * "
			if len(name) > 0:
				if self.param_list.index(param) == 0:
					method += ":(" + name_type + symbol + ")" + name
				else:
					method += " " + name + ":(" + name_type + symbol + ")" + name 
			else:
				return ""
		return method

	def _general_print(self, val_name, val_type):
		
		if val_type is None or val_name is None:
			return u''

		if not isinstance(val_name, str):
			val_name = str(val_name)

		ret = u'\tNSLog(@\"' + val_name + u' value is = %@\" , ' + val_name + u');\n'
		return ret

	def _general_body(self, line_number = 1):
		begin = u"\n{\n"
		body = u""
		for x in xrange(0, line_number):
			index = self.general_int(3)
			if index == 1:
				item_list = Params.StrongType
			elif index == 2:
				item_list = Params.CopyType
			else:
				item_list = Params.StrongType

			val_type = self.general_choice(item_list)
			val_name = self.general_string(8)
			
			if val_type in Params.StrongType or val_type in Params.CopyType:
				val_symbol = u" * "
			else:
				val_symbol = u" "

			val_value = u"[[" + val_type + " alloc] init]"
			
			body += u"\t" + val_type + val_symbol + val_name + u" = " + val_value + u";\n"
			body += self._general_print(val_name, val_type) + "\n"
		
		end = u"\n}"
		
		return begin + body + end


	def general(self, num = 1):
		# print "param num = {0}, lin num = {1}".format(len(self.param_list), num)
		return "\n" + self._general_head() + self._general_body(num)

class GeneralInterface(GeneralObject):
	
	def __init__(self, name):
		super(GeneralObject, self).__init__()
		self.name = name

	def _general_begin(self):
		desc = "\n//===== Begin to auto general code\n"
		begin = u"\n\n#import <Foundation/Foundation.h>\n#import <UIKit/UIKit.h>\n"
		return desc + begin + "@interface " + self.name + " : NSObject\n"

	def _general_attribute(self, num = 1):
		if num < 1:
			return ""

		s = ""
		for x in range(1,3):
			if x == 1:
				type_list = Params.StrongType
				type_name = u'strong'
				middle_symbol = u' * '
			elif x == 2:
				type_list = Params.CopyType
				type_name = u'copy'
				middle_symbol = u' * '
			s += "\n"
			for i in range(0, num):
				value_type = self.general_choice(type_list)
				attribute_name = self.general_from_list(Selector.Param, 2) + str(i) + self.general_from_list(Selector.Param, 1)
				s += "@property(nonatomic, " + type_name + ")" + value_type + middle_symbol + attribute_name + ";\n"
			
		return s


	def _general_body(self, num):
		return self._general_attribute(num)

	def _general_end(self):
		return "\n@end\n"

	def general(self , num):
		return self._general_begin() + self._general_body(num) + self._general_end()

class GeneralImplementation(GeneralObject):
	
	def __init__(self, name):
		super(GeneralObject, self).__init__()
		self.name = name

	def _general_begin(self):
		begin = u"\n// begin general "
		s = "\n#import <Foundation/Foundation.h>\n#import <UIKit/UIKit.h>\n\n\n"
		return  begin + s + "\n\n@implementation " + self.name

	def _general_body(self, method_num=1, max_line_num=10):

		s = u""
		for i in range(0, method_num):
			method_name = self.general_from_list(Selector.Param, 2) + str(i) + self.general_from_list(Selector.Param, 2)
			method_param_num = self.general_int(5)
			method_line_num = self.general_int(max_line_num)
			param_list = []
			for i in xrange(1,method_param_num):
				param_name = self.general_from_list(Selector.Param, 3)
				param_type = self.general_choice(Params.Type)
				p = Params(param_name, param_type)
				param_list.append(p)
			method = GeneralMethod(method_name, param_list)
			s += method.general(method_line_num) + u"\n"
		return s

	def _general_end(self):
		return "\n@end\n"

	def general(self,method_num=1, max_line_num=10):
		'''
		method_num: the number of method to general
		max_line_num: the number of line's of per method
		'''
		return "\n" + self._general_begin() + self._general_body(method_num, max_line_num) + self._general_end()


def general_heard_file(path, class_name ,attribute_number=100):
	with open(path,"a+") as f:
		interface = GeneralInterface(class_name)
		s = "\n#import <Foundation/Foundation.h>\n#import <UIKit/UIKit.h>\n\n\n"
		s += interface.general(attribute_number)
		f.write(s)

def general_implementation_file(path, class_name, method_num=100, max_line_num=100):
	with open(path,"a+") as f:
		s = '\n#import \"' + class_name + ".h\"\n\n\n"
		implementation = GeneralImplementation(class_name)
		s += implementation.general(method_num, max_line_num)
		f.write(s)

def insert_code(path, attribute_number=30, method_number=30 , max_line_num=15):
	if not os.path.exists(path):
		print "path not exist, path = {0}".format(path)
		return

	for file_name in os.listdir(path):
		file_path = os.path.join(path,file_name)
		if os.path.isdir(file_path):
			insert_code(file_path)
		else:
			if cmp(file_name, "main.m") == 0 or cmp(file_name, "main.mm") == 0:
				print "do not need change the main.m file"
			else:	
				if (file_name.endswith(".m") == True) or (file_name.endswith(".mm") == True):
					# print "begin insert code"
					with open(file_path, "a+") as f:
						s = ""
						gen = GeneralObject()
						className = gen.general_from_list(Selector.Param, 4) + "_" + gen.general_string(10)
						interface = GeneralInterface(className)
						s += interface.general(attribute_number)
						implementation = GeneralImplementation(className)
						s += implementation.general(method_number,max_line_num)
						f.write(s)

def general_file(path, num = 10):
	if not os.path.exists(path):
		os.makedirs(path)

	for x in xrange(0,num):
		gen = GeneralObject()
		class_name = gen.general_from_list(Selector.Param, 2) + str(x) + gen.general_from_list(Selector.Param, 2)
		head_path = os.path.join(path, class_name + ".h")
		implement_path = os.path.join(path, class_name + ".m")

		general_heard_file(head_path, class_name, 50)
		general_implementation_file(implement_path, class_name, 100, 50)


class GeneralCode(object):
	def __init__(self, path):
		super(GeneralCode, self).__init__()
		self.path = path

	def run(self, general_type=u'1'):
		if general_type == u'2':
			print 'insert code'
			insert_code(self.path)
		else:
			print 'general code'
			general_file(self.path, 50)

if __name__ == '__main__':
	if len(sys.argv) < 2:
		print 'params count error'
	else:
		print "begin ... "
		before_time = time.time()
		path = sys.argv[1]
		general_type = sys.argv[2]
		obj = GeneralCode(path)
		obj.run(general_type)
		after_time = time.time()
		print("use time:%d s" % (int(after_time - before_time)))

