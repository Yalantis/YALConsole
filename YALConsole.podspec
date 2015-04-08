Pod::Spec.new do |s|

  s.name         = "YALConsole"
  s.version      = "1.0.0"
  s.summary      = "Logging utility for iOS developers and testers"

  s.description  = <<-DESC
                YALConsole is handy and flexible logging utility that integrates into your iOS project. 
                It may be useful to QA engineers that usually do not have access to debugger.
                Besides custom logging you can add counters, observers and actions.
                   DESC

  s.homepage     = "https://github.com/mmrmmlrr/YALConsole"
  s.resource  = "YALConsole.bundle"

  s.vendored_frameworks = "YALConsole.framework"
  s.license      = { :type => "MIT", :file => "LICENSE" }

  s.author             = { "aleksey" => "aleksey.chernish@yalantis.com" }

  s.platform     = :ios
  s.ios.deployment_target = "7.0"

  s.dependency 'KVOController', '~> 1.0.3'
  
end
