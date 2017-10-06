Pod::Spec.new do |s|

s.name             = "MidtransKit"
s.version          = "1.7.2.7"
s.summary          = "Veritrans mobile SDK beta version"
s.homepage         = "https://veritrans.co.id/"
s.license          = 'MIT'
s.author           = { "veritrans" => "dev@veritrans.co.id" }
s.source           = { :git => 'https://github.com/veritrans/Veritrans-ios-sdk.git', :tag => s.version}
s.platform     = :ios, '8.0'
s.requires_arc = true

s.subspec 'UI' do |sp|
end

s.source_files = 'MidtransKit/MidtransKit/**/*.{h,m}'
s.resource_bundles = {
    'MidtransKit' => ['MidtransKit/MidtransKit/resources/*','MidtransKit/MidtransKitResources/*.lproj/*.strings']
}
s.dependency 'MidtransCoreKit', '~> 1.7.2.7'

s.default_subspec = 'UI'

end
